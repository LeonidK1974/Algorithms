// HeapSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// Реализация пирамидальной сортировки на C++ (HeapSort)
#include <iostream>

using namespace std;

static int countHeapify = 0;

/* Вспомогательная функция для вывода на экран массива размера n*/
void printArray(int arr[], int n)
{
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}

// Процедура для преобразования в двоичную кучу поддерева с корневым узлом i, что является
// индексом в arr[]. 
// i - индекс в массиве
// n - размер кучи
void heapify(int arr[], int n, int i)
{
	int largest = i;
	// Инициализируем наибольший элемент как корень
	int l = 2 * i + 1; // левый = 2*i + 1
	int r = 2 * i + 2; // правый = 2*i + 2

 // Если левый дочерний элемент больше корня
	if (l < n && arr[l] > arr[largest])
		largest = l;

	// Если правый дочерний элемент больше, чем самый большой элемент на данный момент
	if (r < n && arr[r] > arr[largest])
		largest = r;

	// Если самый большой элемент не корень
	if (largest != i)
	{
		swap(arr[i], arr[largest]);

		// Рекурсивно преобразуем в двоичную кучу затронутое поддерево
		heapify(arr, n, largest);
	}
	countHeapify++;
	cout << "step heapify: " << countHeapify << ":\t";
	printArray(arr, n);
}

// Основная функция, выполняющая пирамидальную сортировку
void heapSort(int arr[], int n)
{
	// Построение кучи (перегруппируем массив)
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	cout << "Right Heap is build! ";
	printArray(arr, n);

	// Один за другим извлекаем элементы из кучи
	for (int i = n - 1; i >= 0; i--)
	{
		// Перемещаем текущий корень в конец
		swap(arr[0], arr[i]);
		cout << "after swap" << endl;
		printArray(arr, n);

		// вызываем процедуру heapify на уменьшенной куче
		heapify(arr, i, 0);
	}
}

// Управляющая программа
int main()
{
	//int arr[] = { 12, 11, 13, 6, 7, 5 , 2, 3, 1, 0};
	int arr[] = { 5 , 2, 3, 1, 0, 12, 11, 13, 6, 7 };
	//int arr[] = { 4, 10, 3, 5, 1, 2, 7 };
	cout << "Source array is \n";
	int n = sizeof(arr) / sizeof(arr[0]);
	printArray(arr, n);
	cout << endl;

	heapSort(arr, n);

	cout << endl;
	cout << "Sorted array is \n";
	printArray(arr, n);
}



