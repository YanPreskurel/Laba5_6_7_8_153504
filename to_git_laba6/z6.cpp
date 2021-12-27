//Лабораторная 6, задача 6. Выполнена: Прескурел Я.Ю.

/*Анаграммой слова называется любая перестановка всех букв слова. 
Например, из слова SOLO можно получить 12 анаграмм: SOLO, LOSO,
OSLO, OLSO, OSOL, OLOS, SLOO, LSOO, OOLS, OOSL, LOOS, SOOL. 
Напишите программу, которая выводит количество различных 
анаграмм, которые могут получиться из этого слова.*/

#include <iostream>
#include <string>

using namespace std;

int factorial(int a)
{
	int f = 1;

	for (int i = 1; i <= a; i++) 
	{
		f *= i;
	}
	return f;
}

int main()
{
	setlocale(LC_ALL, "rus");

	int count = 0;
	int count2 = 1;

	const int N = 14;
	int arr[N];

	string word;

	cout << "Введите слово: ";
	getline(cin, word);

	for (int i = 0; word[i] != '\0'; i++)
	{
		count++;
	}

	for (int k = 0; k < count - 1; k++)
	{
		for (int i = count - 1; i > k ; i--)
		{
			if (word[k] == word[i])
			{
				if (k > 0 && word[k] == word[k - 1])
				{
					break;
				}
				else if (k > 1 && word[k] == word[k - 2])
				{
					break;
				}
				else if (k > 2 && word[k] == word[k - 3])
				{
					break;
				}
				else if (k > 3 && word[k] == word[k - 4])
				{
					break;
				}
				else if (k > 4 && word[k] == word[k - 5])
				{
					break;
				}
				else if (k > 5 && word[k] == word[k - 6])
				{
					break;
				}
				else if (k > 6 && word[k] == word[k - 7])
				{
					break;
				}
				else if (k > 7 && word[k] == word[k - 8])
				{
					break;
				}
				else if (k > 8 && word[k] == word[k - 9])
				{
					break;
				}
				else if (k > 9 && word[k] == word[k - 10])
				{
					break;
				}
				else if (k > 10 && word[k] == word[k - 11])
				{
					break;
				}
				else if (k > 11 && word[k] == word[k - 12])
				{
					break;
				}
				else if (k > 12 && word[k] == word[k - 13])
				{
					break;
				}
				count2++;
			}
		}
		arr[k] = count2;
		count2 = 1;
	}

	unsigned long long int com = 1;
	
	for (int i = 0; i < N; i++)
	{
		com *= factorial(arr[i]);
	}

	cout << "\n\nЧисло возможных анаграмм: " << factorial(count) / com << endl;

	return 0;
}