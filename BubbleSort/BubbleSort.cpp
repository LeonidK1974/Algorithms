// BubbleSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>
#include <vector>

using namespace std;

//Not optimized
//template<typename T>
//void BubbleSort(vector<T> &v) 
//{
//	for (size_t i = 0; i < v.size() - 1; i++) 
//	{
//		bool swapped = false;
//		for (size_t j = 0; j < v.size() - 1; j++) 
//		{
//			if (v.at(j)  > v.at(j + 1))
//			{
//				swap(v.at(j), v.at(j + 1));
//			}
//		}			
//	}
//}

//Optimization 1
//template<typename T>
//void BubbleSort(vector<T> &v)
//{
//	for (size_t i = 0; i < v.size() - 2; i)
//	{
//		bool swapped = false;
//		for (size_t j = 0; j < v.size() - i - 2; ++j)
//		{
//			if (v.at(j) > v.at(j + 1))
//			{
//				swap(v.at(j), v.at(j + 1));
//			}
//		}
//	}
//}

//Optimization 2
//template<typename T>
//void BubbleSort(vector<T> &v)
//{
//	int i = 0;
//	bool swapped = true;
//	while (swapped)
//	{
//		swapped = false;
//		for (size_t j = 0; j < v.size() - i - 1; j++)
//		{
//			if (v.at(j) > v.at(j + 1))
//			{
//				swap(v.at(j), v.at(j + 1));
//				swapped = true;
//			}
//		}
//		i = i + 1;
//	}
//}

//Optimization 2 variant 2
template<typename T>
void BubbleSort(T &v)
{
	for (size_t i = 0; i < v.size() - 1; i++)
	{
		bool swapped = false;
		for (size_t j = 0; j < v.size() - i - 1; j++)
		{
			if (v[j] > v[j + 1])
			{
				swap(v[j], v[j + 1]);
				swapped = true;
			}
		}

		if (!swapped) break;
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
	vector<int> v = {3,6,5,4,1,2,7,0};
	Print(v);
	BubbleSort(v);
	Print(v);

	/*list<int> l = { 3,6,5,4,1,2,7,0 };
	Print(l);
	BubbleSort(l);
	Print(l);*/

}


