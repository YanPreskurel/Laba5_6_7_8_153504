//Лабораторная 7, задача 1. Выполнена: Прескурел Я.Ю.

/*Необходимо разработать программу для перевода чисел из 
одной системы счисления в другую. Выполнить два варианта решения 
задачи: без использования массивов и с помощью массивов.
	Вариант 3: из тринадцатеричной в пятеричную*/

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int num(long long int value)
{
	long long int a = value;
	int t = 0;
	while (a > 0)
	{
		a /= 10;
		t++;
	}
	return t;
}

int main()
{
	setlocale(LC_ALL, "rus");

	const int size = 100;
	long long int digit = 0;
	char s[size];

	cout << "Введите число в 13-ричной системе: ";
	gets_s(s);

	cout << "\n\n0 = 0, 1 = 1, 2 = 2, 3 = 3, 4 = 4, 5 = 5, 6 = 6, 7 = 7, 8 = 8, 9 = 9, A = 10, B = 11, C = 12\n\n";

	int a = strlen(s) - 1;

	for (int i = 0; i < strlen(s); i++)
	{
		if (s[i] == 'A' || (s[i] == 'B') || (s[i] == 'C'))
		{
			digit += (s[i] - 55) * pow(13, a);
			a--;
		}
		else 
		{
			digit += (s[i] - 48) * pow(13, a);
			a--;
		}
	}
	
	cout << "В десятичной: " << digit << "\n\n";

	int temp = 0;
	int k = 0;

	while (true)
	{
		if (digit >= pow(5, k))
		{
			k++;
		}
		else break;
	}

	int five = 0;
	temp = 0;

	while (temp!=k)
	{
		five += (digit % 5) * pow(10, temp);
		temp++;
		digit /= 5;
	}
	cout << "\nВ пятеричной системе: " << five << endl;

	return 0;
}