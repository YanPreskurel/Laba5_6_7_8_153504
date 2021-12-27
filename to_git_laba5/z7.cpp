//Лабораторная 5, задача 7. Выполнена: Прескурел Я.Ю.

/*Рекурсивная функция задана следующим образом:
f(0,0) = 1
f(n,r) = сумме f(n-1, r-i), i = 0, до того пока не станет i = k - 1,
when [(n > 0) and (0 <= r < n * (k - 1) + 1)]
f(n,r) = 0, otherwise
Вычислить значение x = Сумме f(n, i) % m, когда i = 0,
до того пока не станет i = n * (k - 1), где m = 10^t. */

#include <iostream>

using namespace std;

long long Recursion_func(unsigned long long c, unsigned long long n, unsigned long long m) //рекурсивная функция
{
	if (n == 0)
	{
		return 1;
	}
	if (n & 1)
	{
		return c * Recursion_func(c * c % m, n / 2, m) % m;
	}
	return Recursion_func(c * c % m, n / 2, m);
}

int main()
{
	setlocale(LC_ALL, "rus");

	int count = 1; // Счётчик
	unsigned long long int k, n, m, t, result;

	while (cout << "Введите значения переменных k, n и t: " && cin >> k >> n >> t) // Пока пользователь не введет 0 0 0, 	
	{                                                                             // программа будет запрашивать данные
		if (k == 0 && n == 0 && t == 0)
		{
			break; // выход из циклы
		}

		m = pow(10, t);
		unsigned long long int c = k % m; // упрощение задачи 

		result = Recursion_func(c, n, m); 

		cout << "\nCase #" << count++ << ": " << result << "\n\n"; // вывод ответа
	}
	return 0;
}