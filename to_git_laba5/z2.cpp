//Лабораторная 5, задача 2. Выполнена: Прескурел Я.Ю.

/*Вариант 3.
	Для заданного одномерного массива B из N элементов найти произведение 
множителей, вычисляемых по формуле B(i)^2 + cos B(i). Рекурсивную функцию 
применять каждый раз отдельно для каждой из половин массива. Рекурсивные вызовы 
заканчивать, когда останется только один элемент.*/

#include <iostream>
#include <iomanip>
#include <Windows.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	HINSTANCE load;
	load = LoadLibrary(L"DynamicLib.dll");
	typedef double (*recursive_func) (int, int, double*);

	recursive_func Recursive_func;
	Recursive_func = (recursive_func)GetProcAddress(load, "Recursive_func");

	int N;

	cout << "Введите кол-во элементов: ";
	while (!(cin >> N) || (cin.peek() != '\n') || N < 1 && N > 100)
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "\nПроизошла ошибка" << endl;
		cout << "\nВведите кол-во элементов: ";
	}

	double* arr = new double[N];

	for (int i = 0; i < N; i++)
	{
		cout << "Введите [" << i << "] элемент массива: ";
		while (!(cin >> arr[i]) || (cin.peek() != '\n'))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "\nПроизошла ошибка" << endl;
			cout << "\nВведите[" << i << "] элемент массива : ";
		}
	}

	double answer = Recursive_func(N / 2, N - 1, arr) * Recursive_func(0, N / 2 - 1, arr);

	cout << "\n\nПроизведение множителей = " << answer << endl;
	
	delete[] arr;
	FreeLibrary(load);

	return 0;
}