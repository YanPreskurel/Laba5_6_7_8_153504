//Лабораторная 5, задача 1. Выполнена: Прескурел Я.Ю.

/*Вариант 3.
	Сформировать два двумерных динамических массива-матрицы A и B
размерностью n * n. Размерность массивов (n = 10) ввести с клавиатуры.
Значения элементов a[i][j] и b[i][j] определить согласно выражениям.
Определить суммы элементов, расположенных по периметру, для данных
массивов-матриц. Использовать функции. Вывести на экран полученные 
массивы в виде матриц и значения сумм.*/
	
#include <iostream>
#include "../StaticLib(1)/StaticLib1.h"

using namespace std;

int main()
{	
	setlocale(LC_ALL, "rus");

	int N; 

	cout << "Введите размеры массивов N: ";

	while (!(cin >> N) || (cin.peek() != '\n') || N < 2 && N > 100)
	{
		cin.clear();
		while (cin.get() != '\n' );
		cout << "\nПроизошла ошибка" << endl;
		cout << "\nВведите размеры массивов N: ";
	}

	int** arr = new int* [N];
	int** arr2 = new int* [N];

	Create_Array2(arr, arr2, N);
	InputArray(arr, arr2, N);
	Output(arr, arr2, N);
	Desicion(arr, arr2, N);
	Delete_Array(arr, arr2, N);

	return 0;
}