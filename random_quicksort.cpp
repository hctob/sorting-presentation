#include <iostream>
#include <chrono>
#include <random>
//#include <functional>

namespace RQS {
    int partition(int* arr, size_t start, size_t end) {
        //choose randomized pivot point beween start and end
        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution<std::mt19937::result_type> pv(start, end - 1);
	    size_t pivot = arr[pv(rng)];
        size_t i = start - 1;

        //from the start index to the end index of the partition
        for(size_t j = start; j <= end - 1; j++) {
            if(arr[j] <= (int)pivot) {
                i++;
                std::swap(arr[i], arr[j]);
            }
        }
        std::swap(arr[i + 1], arr[end]);
        return i + 1;
    }
    void quicksort(int* arr, size_t start, size_t end) {
        if(start < end) {
            //get pivot point for quicksort based on relative start and end points
            int p = partition(arr, start, end);
            //std::cout << "P = " << p << std::endl;
            //perform quicksort on the left partition
            quicksort(arr, start, p - 1);
            //perform quicksort on the right partition
            quicksort(arr, p + 1, end);
        }
    }
}
