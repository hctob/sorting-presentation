#include <iostream>
#include <chrono>
#include <random>
#include <functional>
#include "quicksort.cpp"
#include "insertion_sort.cpp"
#include "mergesort.cpp"
#include "random_quicksort.cpp"

//Insertion, merge, quick, and randomized quicksort

namespace Driver {
    int* generate_rand_array(size_t size) {
        std::default_random_engine generator;
        std::uniform_int_distribution<int> distribution(0, size / 2);
        auto gen_rand = std::bind(distribution, generator);
        //std::vector<int> qs_array(end);
        int* new_array = new int[size];
        for(size_t i = 0; i < size; i++) {
            new_array[i] = gen_rand();
        }
        /*std::cout << "Array of size " << size << " before sort: ";
        for (auto i = 0; i < (int)size; i++) {
            std::cout << new_array[i] << " ";
        }*/
        //std::cout << std::endl;
        return new_array;
    }

    //default start value is 0
    //generates an int array of size size with values start...size
    int* generate_sorted_array(size_t size, int start = 0) {
        int* new_array = (int*)malloc(sizeof(int) * size); //create an array of size size on the heap
        for(size_t i = 0; i < size; ++i) {
            new_array[i] = start + i;
        }

        return new_array;
    }

    template <typename ResultType, typename ...ArgumentTypes>
    auto do_action(ResultType&& f, ArgumentTypes&&... args) {
        auto func = std::move(f);

        auto start = std::chrono::steady_clock::now(); //save the current time as the 'start' timestamp
        func(args...);
        auto end = std::chrono::steady_clock::now(); //save the current time as the 'end' timestamp

        std::chrono::duration<double> diff = (end - start); //save the difference between the end and start as 'diff'

        return diff.count(); //return diff (the approximate number of seconds to execute the algorithm with the specified args)
    }

    void go(std::string type) {
        for(size_t i = 1; i < 8; i++) {
            size_t bound = std::pow(10, i);
            //auto arr = generate_rand_array(bound);

            if(type == "insertion_sort") {
                    auto arr = generate_rand_array(bound);
                    auto ret = Driver::do_action(IS::insertion_sort, arr, bound);
                    std::cout << "Time to " << type << " array of " << bound << " elements: " << ret << " seconds.\n";
                    free(arr);
            }

            //first argument of do-action is the sort you want to test the performance of
            //next arguments are the arguments of the sort function
            else if(type == "mergesort") {
                    auto arr = generate_rand_array(bound);
                    //printf("Breaks after generating random array");
                    auto ret = Driver::do_action(MS::mergesort, arr, 0, bound - 1);
                    std::cout << "Time to " << type << " array of " << bound << " elements: " << ret << " seconds.\n";
                    free(arr);
            }
            else if(type == "quicksort") {
                    auto arr = generate_rand_array(bound);
                    auto ret = Driver::do_action(QS::quicksort, arr, 0, bound);
                    std::cout << "Time to " << type << " array of " << bound << " elements: " << ret << " seconds.\n";
                    free(arr);

		    /*auto sorted = generate_sorted_array(10000, 0); //sorting on pre-sorted array
		    auto ret2 = Driver::do_action(QS::quicksort, sorted, 0, 10000);

		    std::cout << "Time to " << type << " sorted array of " << bound << " elements: " << ret2 << " seconds.\n";
		    free(sorted);*/
            }
            else if(type == "random_quicksort") {
                    auto arr = generate_rand_array(bound);
                    auto ret = Driver::do_action(RQS::quicksort, arr, 0, bound);
                    std::cout << "Time to " << type << " array of " << bound << " elements: " << ret << " seconds.\n";
                    free(arr);
            }
            else {
                std::cout << "ERROR: unknown sort type.\n";
        std::cout << "insertion_sort: runs insertion_sort\nmergesort: runs mergesort\nquicksort: runs quicksort\nrandom_quicksort: runs randomized quicksort\n";
                exit(1);
            }
        }
    }
}


int main(int argc, char** argv) {
    /*For each sorting function, call Driver::do("name of sort");*/
    if(argc != 2) {
        std::cout << "Usage: ./sort-driver <name of sort>" << std::endl;
        std::cout << "insertion_sort: runs insertion_sort\nmergesort: runs mergesort\nquicksort: runs quicksort\nrandom_quicksort: runs randomized quicksort\n";
        exit(1);
    }
    else {
        auto option = argv[1];
        Driver::go(option);
    }
    //Insertion sort
   // Driver::go("insertion_sort");
    //Merge sort
    //Driver::go("mergesort");
    //Quicksort
    //Driver::go("quicksort");

    //Randomized quicksort
    //Driver::go("random_quicksort");


    return 0;
}
