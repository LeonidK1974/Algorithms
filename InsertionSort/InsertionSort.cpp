// InsertionSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

template<typename T>
void InsertionSort(T &v)
{
	for (size_t i = 1; i < v.size(); i++)
	{
		for (int j = i; j > 0 && v[j - 1] > v[j]; j--)
		{
			swap(v[j - 1], v[j]);
		}

	}
}

// Internal insertion sort routine for subarrays
// that is used by quicksort.
// a is an array of Comparable items.
// low is the left-most index of the subarray.
// high is the right-most index of the subarray.
template <class Comparable>
void InsertionSort(vector<Comparable> & v, int low, int high)
{
	for (int p = low + 1; p <= high; p++)
	{
		int j;
		Comparable tmp = v[p];
		for (j = p; j > low && tmp < v[j - 1]; j--)
			swap(v[j - 1], v[j]);
		v[j] = tmp;

	}
}

template<typename T>
void Print(const T &v)
{
	for (auto item : v)
	{
		cout << item << " ";
	}
	cout << endl;
}

int main()
{
	vector<int> v = { 3,6,5,4,1,2,7,0 };
	Print(v);
	//InsertionSort(v); // полная сортировка
	InsertionSort(v, 4, 7); // интервальная сортировка
	Print(v);
}

