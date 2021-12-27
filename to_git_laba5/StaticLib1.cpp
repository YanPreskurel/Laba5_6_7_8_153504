#include <iostream>
#include "StaticLib1.h"

using namespace std;

void Create_Array2(int** arr, int** arr2, int N)
{
	for (int i = 0; i < N; i++)
	{
		arr[i] = new int[N];
	}

	for (int i = 0; i < N; i++)
	{
		arr2[i] = new int[N];
	}
}

void InputArray(int** arr, int** arr2, int N)
{
	for (int i = 0; i < N; i++)  //Заполнение 1 массива
	{
		for (int j = 0; j < N; j++)
		{
			if (i < 6)
			{
				arr[i][j] = 3 * i * (j - 3);
			}
			if (i > 5)
			{
				arr[i][j] = 2 * i * (j - 2);
			}
		}
	}

	for (int i = 0; i < N; i++)	//Заполнение 2 массива
	{
		for (int j = 0; j < N; j++)
		{
			if (i < 8)
			{
				arr2[i][j] = 5 * i * (j - 4);
			}
			if (i > 7)
			{
				arr2[i][j] = 4 * i * (j - 5);
			}
		}
	}
}

void Desicion(int** arr, int** arr2, int N)
{
	int sum = 0, sum2 = 0;

	for (int i = 0; i < N; i++)
	{
		sum += arr[i][0] + arr[i][N - 1];
		sum2 += arr2[i][0] + arr2[i][N - 1];
	}
	for (int j = 1; j < N - 1; j++)
	{
		sum += arr[0][j] + arr[N - 1][j];
		sum2 += arr2[0][j] + arr2[N - 1][j];
	}
	cout << "\n\nCумма элементов периметра первого массива = " << sum;
	cout << "\n\nСумма лементов периметра второго массива = " << sum2 << "\n\n";
}

void Output(int** arr, int** arr2, int N)
{
	cout << "\n\nПервый массив:\n\n";

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << arr[i][j] << '\t';
		}
		cout << "\n\n";
	}

	cout << "\n\nВторой массив:\n\n";

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << arr2[i][j] << '\t';
		}
		cout << "\n\n";
	}
}

void Delete_Array(int** arr, int** arr2, int N)
{
	for (int i = 0; i < N; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;

	for (int i = 0; i < N; i++)
	{
		delete[] arr2[i];
	}
	delete[] arr2;
}

