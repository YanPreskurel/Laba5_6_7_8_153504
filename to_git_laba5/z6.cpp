//Лабораторная 5, задача 6. Выполнена: Прескурел Я.Ю.

/*Определим следующую рекурсивную функцию F(n):

F(n) = n % 10, if(n % 10 > 0)
F(n) = 0, if(n = 0)
F(n) = F(n / 10), otherwise
Определим функцию S (p, q) следующим образом:
S (p, q) = cумме F(i), когда i = p, до того пока не станет i = q
По заданным p и q необходимо вычислить S (p, q).*/

#include <iostream>

using namespace std;

int Recursive_func(int i)
{
	if (i % 10 > 0)
	{
		return i % 10;
	}
	else if (i == 0)
	{
		return 0;
	}
	else
	{
		return Recursive_func(Recursive_func(i / 10));
	}
}

int S(int p, int q)
{
	int sum = 0;

	for (int i = p; i < q + 1; i++)
	{
		sum += Recursive_func(i);
	}

	return sum;
}

int main()
{
	setlocale(LC_ALL, "rus");

	int p, q;

	cout << "Введите значение p и q: ";
	while (!(cin >> p) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "\nПроизошла ошибка" << endl;
		cout << "\nВведите значение p и q: ";
	}
	while (!(cin >> q) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "\nПроизошла ошибка" << endl;
		cout << "\nВведите значение p и q:  ";
	}

	cout << "\n\nСумма = " << S(p, q) << endl;
	

	return 0;
}