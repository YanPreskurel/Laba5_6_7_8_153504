//Лабораторная 7, задача 2. Выполнена: Прескурел Я.Ю.

/* Перевести числа. Предусмотреть ввод положительных и
отрицательных чисел.
	Вариант3: Из обратного кода в естественную форму*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	char arr[100];
	gets_s(arr);

	if (arr[0] == '1')
	{
		for (int i = 1; i < strlen(arr); i++)
		{
			if (arr[i] == '0')
			{
				arr[i] = '1';
			}
			else
			{
				arr[i] = '0';
			}
		}
	}
	
	for (int i = 0; i < strlen(arr); i++)
	{
		cout << arr[i];
	}

	int a = strlen(arr) - 2;
	long long digit = 0;

	for (int i = 1; i < strlen(arr); i++)
	{
			digit += (arr[i] - 48) * pow(2, a);
			a--;
	}
	if (arr[0] == '1')
	{
		digit *= -1;
	}

	cout << "\n\nЧисло в естественной форме: " << digit << endl;

	return 0;
}