//Лабораторная 5, задача 4. Выполнена: Прескурел Я.Ю.

/*Создать двумерный динамический массив вещественных чисел. Определить, 
встречаются ли среди них элементы с нулевым значением. Если встречаются такие 
элементы, то определить их индексы и общее количество. Переставить элементы этого 
массива в обратном порядке и вывести на экран.
Использовать функции*/

#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));

	int N, M, counter = 0, count = 0;

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

	double** arr = new double* [N];

	for (int i = 0; i < N; i++)
	{
		arr[i] = new double[M];
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			arr[i][j] = rand() % 10 * 0.3;
		}
	}

	cout << "\n";

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << arr[i][j] << '\t';
		}
		cout << "\n\n";
	}

	cout << "\n\nИндексы:";

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] == 0)
			{
				counter++;
				cout << "[" << i << ", " << j << "]\t";
			}		
		}
	}

	cout << "\n\nОбщее кол-во нулей: " << counter << "\n\n";

	int exit = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (N * M / 2 == count)
			{
				exit = 1;
				break;
			}		
			swap(arr[i][j], arr[N - 1 - i][M - 1 - j]);
			count++;
		}
		if (exit == 1)
		{
			break;
		}
	}

	cout << "\n\n";

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << arr[i][j] << '\t';
		}
		cout << "\n\n";
	}

	for (int i = 0; i < N; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;

	return 0;
}