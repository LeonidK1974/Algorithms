// SortingUnited.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Sort.h"
//#include "Permute.cpp"

#ifndef SAFE_STL
#include <vector>
using namespace std;
#else
#include "vector.h"
#include "StartConv.h"
#endif

void permute(vector<int> & a);

void checkSort(const vector<int> & a)
{
	for (size_t i = 0; i < a.size(); i++)
		if (a[i] != i + 1)
			cout << "Error at " << i << endl;
	cout << "Finished checksort" << endl;
}

int main()
{
	const int NUM_ITEMS = 1000;

	vector<int> a(NUM_ITEMS);

	for (int theSeed = 0; theSeed < 20; theSeed++)
	{
		permute(a);
		insertionSort(a);
		checkSort(a);

		permute(a);
		shellsort(a);
		checkSort(a);

		permute(a);
		mergeSort(a);
		checkSort(a);

		permute(a);
		quicksort(a);
		checkSort(a);

		permute(a);
		largeObjectSort(a);
		checkSort(a);

		permute(a);
		quickSelect(a, NUM_ITEMS / 2);
		cout << a[NUM_ITEMS / 2 - 1] << " " << NUM_ITEMS / 2 << endl;
	}

	return 0;
}
