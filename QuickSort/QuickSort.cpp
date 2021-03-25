// QuickSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

#define swap swapItems

// Standard swap
template <class Comparable>
inline void swap(Comparable & obj1, Comparable & obj2)
{
	Comparable tmp = obj1;
	obj1 = obj2;
	obj2 = tmp;
}

// Simple insertion sort.
// Internal insertion sort routine for subarrays
// that is used by quicksort.
// a is an array of Comparable items.
// low is the left-most index of the subarray.
// high is the right-most index of the subarray.
template <class Comparable>
void insertionSort(vector<Comparable> & a, int low, int high)
{
	for (int p = low + 1; p <= high; p++)
	{
		Comparable tmp = a[p];
		int j;

		for (j = p; j > low && tmp < a[j - 1]; j--)
			a[j] = a[j - 1];
		a[j] = tmp;
	}
}

// Internal quicksort method that makes recursive calls.
// Uses median-of-three partitioning and a cutoff of 10.
// a is an array of Comparable items.
// low is the left-most index of the subarray.
// high is the right-most index of the subarray.
template <class Comparable>
void quicksort(vector<Comparable> & a, int low, int high)
{
	if (low + 10 > high)
		insertionSort(a, low, high);
	else
	{
		// Sort low, middle, high
		int middle = (low + high) / 2;
		if (a[middle] < a[low])
			swap(a[low], a[middle]);
		if (a[high] < a[low])
			swap(a[low], a[high]);
		if (a[high] < a[middle])
			swap(a[middle], a[high]);

		// Place pivot at position high - 1
		Comparable pivot = a[middle];
		swapItems(a[middle], a[high - 1]);

		// Begin partitioning
		int i, j;
		for (i = low, j = high - 1; ; )
		{
			while (a[++i] < pivot) {}
			while (pivot < a[--j]) {}
			if (i < j)
				swap(a[i], a[j]);
			else
				break;
		}
		swap(a[i], a[high - 1]);  // Restore pivot

		quicksort(a, low, i - 1);     // Sort small elements
		quicksort(a, i + 1, high);    // Sort large elements
	}
}

// Quicksort algorithm (driver).
template <class Comparable>
void quicksort(vector<Comparable> & v)
{
	
	quicksort(v, 0, v.size() - 1);

	for (auto i : v)
	{
		cout << i << " ";
	}
}

int main()
{
	vector<int> v = { 10, 4, 3, 1, 9, 12, 5, 8, 0, 2, 6, 7, 11 };
	quicksort(v);
}

