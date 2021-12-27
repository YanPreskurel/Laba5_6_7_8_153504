//Лабораторная 7, задача 6. Выполнена: Прескурел Я.Ю.

#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

    long long int t;

    cout << "Введите кол-во наборов: ";
    cin >> t;

    while (t--)
    {
        long long int x;

        cout << "\nВведите число: ";
        cin >> x;

        cout << "\n" << (x + 1) / 10 << endl;
    }
	return 0;
}