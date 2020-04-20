all:	main
main:	sorts.o
	g++ -std=c++14 -Wall -Wextra -pedantic -g main.o -o sort-driver

sorts.o:	main.cpp quicksort.cpp mergesort.cpp insertion_sort.cpp
	g++ -std=c++14 -Wall -Wextra -pedantic -g -c main.cpp

qs:	qs.o
	g++ -std=c++14 -Wall -Wextra -pedantic -g quicksort.o -o quicksort-driver

qs.o:	quicksort.cpp
	g++ -std=c++14 -Wall -Wextra -pedantic -g -c quicksort.cpp

ms: ms.o
	g++ -std=c++14 -Wall -Wextra -pedantic -g mergesort.o -o mergesort-driver

ms.o: mergesort.cpp
	g++ -std=c++14 -Wall -Wextra -pedantic -g -c mergesort.cpp

is: is.o
	g++ -std=c++14 -Wall -Wextra -pedantic -g insertion_sort.o -o insertionsort-driver

is.o: insertion_sort.cpp
	g++ -std=c++14 -Wall -Wextra -pedantic -g -c insertion_sort.cpp

clean:
	rm -f *.o sort-driver
