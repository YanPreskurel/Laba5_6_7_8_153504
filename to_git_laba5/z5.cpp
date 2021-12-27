//Лабораторная 5, задача 5. Выполнена: Прескурел Я.Ю.

/*Дан двумерный динамический массив целых чисел. Значения элементов данного 
массива ввести с клавиатуры. Создать динамический массив из элементов, 
расположенных в четных столбцах данного массива и имеющих нечетное значение. 
Вычислить среднее арифметическое элементов динамического массива.
Вывести результат на экран.
Использовать функции*/

#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	int N, M, dif = 0, k = 0;
	double mid = 0;

	cout << "Введите размер массива NxM: ";
	while (!(cin >> N) || (cin.peek() != '\n') || N < 1)
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "\nПроизошла ошибка" << endl;
		cout << "\nВведите размеры массивов N: ";
	}
	while (!(cin >> M) || (cin.peek() != '\n') || M < 1)
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "\nПроизошла ошибка" << endl;
		cout << "\nВведите размеры массивов N: ";
	}

	int** arr = new int* [N];

	for (int i = 0; i < N; i++)
	{
		arr[i] = new int[M];
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << "Введите [" << i << ", " << j << "] элемент массива ";
			while (!(cin >> arr[i][j]) || (cin.peek() != '\n'))
			{
				cin.clear();
				while (cin.get() != '\n');
				cout << "\nПроизошла ошибка" << endl;
				cout << "\nВведите [" << i << ", " << j << "] элемент массива ";
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << arr[i][j] << '\t';
		}
		cout << "\n\n";
	}

	int* arr2 = new int[M / 2 * N - dif];

	for (int i = 0; i < N; i++)
	{
		for (int j = 1; j < M; j += 2)
		{
			if (arr[i][j] % 2 != 0)
			{
				arr2[k] = arr[i][j];
				k++;
			}
			else
			{
				dif++;
			}
		}		
	}

	for (int i = 0; i < (M / 2 * N - dif); i++)
	{
		mid += arr2[i];
	}

	cout << "\nСозданный массив:\n\n";

	for (int i = 0; i < (M / 2 * N - dif); i++)
	{
		cout << arr2[i] << '\t';
	}

	cout << "\n\nСреднее арифметическое = " << mid / (M / 2 * N - dif) << '\n';

	for (int i = 0; i < N; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;

	delete[] arr2;

	return 0;
}