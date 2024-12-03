Sorting Algorithms Implementation in C++ :-


This project implements various sorting algorithms in C++ within a class structure. Each sorting algorithm is encapsulated in a method, allowing you to easily apply different sorting techniques to a given dataset.

Overview :-

The sorting class provides implementations for several popular sorting algorithms, both recursive and iterative. Each method sorts a vector of integers in ascending order. You can switch between algorithms by uncommenting the corresponding function call in the main() function.

Implemented Algorithms :-

Merge Sort (Recursive & Iterative)
Quick Sort
Heap Sort
Selection Sort
Insertion Sort
Counting Sort
Bubble Sort
Detailed Method Descriptions:
merge(): Helper function for merging two sorted arrays.
findpivot(): Finds the pivot for quick sort.
Heapify(): Ensures the max-heap property in the array.

How to Use :-

Create an instance of the sorting class:-

sorting obj;

Choose a sorting algorithm: Uncomment the desired sorting method call in main() :-


// obj.mergesort(nums);

// obj.bubblesort(nums);

// obj.countingsort(nums);

// obj.heapsort(nums);

// obj.insertionsort(nums);

// obj.iterativeMergeSort(nums);

// obj.quicksort(nums);

// obj.selectionsort(nums);

Provide input data: Initialize a vector<int> with the data you want to sort:


vector<int> nums = {1, 5, 3, 7, 8, 4, 6, 2, 0, 5, 22, 6, -55, 9};


Display the sorted output: The for loop at the end of main() prints the sorted array.
