#include <iostream>
#include <time.h>
#include<stdio.h>
#include <math.h>


void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int arr[], int low, int high)
{
	int pivot = arr[high];  
	int i = (low - 1); 

	for (int j = low; j <= high - 1; j++)
	{

		if (arr[j] <= pivot)
		{
			i++; 
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{

		int pi = partition(arr, low, high);

		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

void bubbleSort(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)

		// Last i elements are already in place   
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
}

void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		std::cout << arr[i] <<  "\n";
}

void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	int L[1000], R[1000];

	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	i = 0; 
	j = 0; 
	k = l;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}


	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}


	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}


void mergeSort(int arr[], int l, int r)
{
	if (l < r)
	{
		
		int m = l + (r - l) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}

int main(int argv , char** argc)
{
	int myArray[1000];
	int i, j;
	int temp = 0;
	int num;
	
	srand(time(0));
	
	for (i = 0; i < 1000; i++){
		num = rand() % 1000 + 1;
		myArray[i] = num;
		}

	int n = sizeof(myArray) / sizeof(myArray[0]);

	clock_t t = clock();
	//Descomentar para ver el tiempo de cada algoritmo con el mimso arreglo

	quickSort(myArray, 0, n - 1);
	//bubbleSort(myArray, n);
	//mergeSort(myArray, 0, n - 1);
	printArray(myArray, n);

	t = clock() - t;

	std::cout << "Tiempo de algoritmo : " << ((float)t) / CLOCKS_PER_SEC << "s \n";


	system("pause");
	return 0;
}