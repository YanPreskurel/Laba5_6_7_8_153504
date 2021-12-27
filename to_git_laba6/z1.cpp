//Лабораторная 6, задача 1. Выполнена: Прескурел Я.Ю.

/*Вариант 3.
	В строке, состоящей из групп нулей и единиц, подсчитать 
количество символов в самой длинной группе.*/

#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	char row[100];
	int count = 1, group = 1;

	cout << "Введите строку из 0 и 1: ";
	cin >> row;

	for (int i = 0; row[i] != '\0'; i++)
	{
		if (row[i] == row[i + 1])
		{
			++count;
			if (group < count)
			{
				group = count;
			}
		}
		else
		{
			count = 1;
		}
	}

	cout << "\n\nВаша строка: " << row << endl;
	cout << "\n\nКол-во символов в самой длинной группе: " << group << endl;

	return 0;
}