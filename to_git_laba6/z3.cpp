//Лабораторная 6, задача 3. Выполнена: Прескурел Я.Ю.

/*Вариант 3.
	  Написать программу, которая, анализируя массив, состоящий из 
строк, выводит на экран количество слов женского, мужского и среднего 
рода. Стандартных функций работы со строками не использовать.*/

#include <iostream>
#include <string>
#include<regex>
#include <Windows.h>

using namespace std;

void checkGender(const string& text, const int& position)
{
	if (text[position] == 'а' || text[position] == 'я' || text[position] == 'ь' || text[position] == 'я')
	{
		cout << " - слово женского рода" << endl;
	}
	else if (text[position] == 'о' || text[position] == 'е' )
	{
		cout << " - слово среднего рода" << endl;
	}
	else
	{
		cout << " - слово мужского рода" << endl;
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "rus");


	string text;
	getline(cin, text);

	for (int i = 0; i < text.length(); i++)
	{
		cout << text[i];

		if (text[i] == ' ' && i != 0)
		{
			checkGender(text, i - 1);
		}		
		if (i == text.length() - 1)
		{
			checkGender(text, i);
		}
	}
	return 0;
}