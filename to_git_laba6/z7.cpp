//Лабораторная 6, задача 7. Выполнена: Прескурел Я.Ю.

/*В заданной строке S найти максимальную по длине подстроку, которая 
не является палиндромом.
Формат входных данных:
На вход задается строка S, состоящая из строчных букв латинского 
алфавита (1 ? |S| ? 105 ).
Формат выходных данных:
Выведите одно целое число — длина максимального непалиндрома. 
Если такой подстроки не существует, то выведите -1*/

#include <iostream>
#include <string>
#include<Windows.h>

using namespace std;

bool eqchar(string s) // Проверка, является ли строка множеством одинаковых символов
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != s[0])
        {
            return false;
        }
    }
    return true;
}

bool ispal(string s) // Проверка, является ли строка палиндромом
{
    for (int i = 0; i < s.length() / 2; i++)
    {
        if (s[i] != s[s.length() - i - 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

        string s;

        cout << "Введите строку: ";
        getline(cin, s);

        if (eqchar(s))
        {
            cout << -1;
        }
        else
        {
            cout << "\n\nРазмер максимальной подстроки, которая не является палиндромом: ";

            if (!ispal(s))
            {
                cout << s.length();
            }
            else 
            {
                if (s[0] < s[1])
                {
                    cout << s.length() - 1;
                }
                else
                {
                    cout << s.length() - 1;
                }
            }
        }
        cout << endl;
     
	return 0;
}