//Лабораторная 5, задача 8. Выполнена: Прескурел Я.Ю.

/*Пусть f(n) - наибольший нечетный делитель натурального числа n.По заданному
натуральному n необходимо вычислить значение суммы f(1) + f(2) + ... + f(n).*/

#include <iostream>

int function(int i)
{
	if (i % 2 != 0)
	{
		return i;
	}
	else
	{
		while (i % 2 != 1)
		{
			i = i / 2;
		}
		return i;
	}
}

int sum(int n)
{
	long long int sum = 0;

	for (int i = 1; i < n + 1; i++)
	{
		sum += function(i);
	}

	return sum;
}

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	int n;

	cout << "Введите натуральное число n: ";
	while (!(cin >> n) || (cin.peek() != '\n') || n < 1)
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "\nПроизошла ошибка" << endl;
		cout << "\nВведите значение p и q: ";
	}

	cout << "\n\nСумма наибольших нечетных делителей = " << sum(n) << endl;

	return 0;
}