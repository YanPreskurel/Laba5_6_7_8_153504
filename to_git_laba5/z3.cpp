//Лабораторная 5, задача 3. Выполнена: Прескурел Я.Ю.

/*Дан двумерный динамический массив целых чисел А размерностью n * k . 
Размерность массива (n = 5, k = 6) ввести с клавиатуры. Значения элементов массива 
ввести с клавиатуры. Создать динамический массив из элементов, расположенных на 
главной диагонали матрицы и имеющих четное значение. Вычислить произведение 
элементов динамического массива. Созданный массив и результат произведения
вывести на экран. Использовать функции*/

#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	int N, M, k = 0, dif = 0, com = 1;

	cout << "Введите размер массива NxM: ";
	cin >> N >> M;
	while (!(cin >> N) || (cin.peek() != '\n') || N < 1)
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "\nПроизошла ошибка" << endl;
		cout << "\nВведите размер массива NxM: ";
	}
	while (!(cin >> M) || (cin.peek() != '\n') || M < 1)
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "\nПроизошла ошибка" << endl;
		cout << "\nВведите размер массива NxM:";
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

	cout << "\n\n";

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << arr[i][j] << '\t';
		}
		cout << "\n\n";
	}

	int* arr2 = new int[N - dif];

	for (int i = 0, j = 0; i < N; i++, j++)
	{
		if (arr[i][j] % 2 == 0)
		{
			arr2[k] = arr[i][j];
			k++;
		}
		else
		{
			dif++;
		}
	}

	for (int i = 0; i < N - dif; i++)
	{
		com *= arr2[i];
	}

	cout << "Созданный массив:\n";
	for (int i = 0; i < N - dif; i++)
	{
		cout << arr2[i] << '\t';
	}

	cout << "\n\nПроизведение элементов массива = " << com << endl;

	delete[] arr2;

	for (int i = 0; i < N; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;

	return 0;
}