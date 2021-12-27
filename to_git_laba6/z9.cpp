//Лабораторная 6, задача 9. Выполнена: Прескурел Я.Ю.

/*Сумма чисел в строке:
В заданной строке, состоящей из букв, цифр и прочих символов, 
найдите сумму всех чисел*/

#include <iostream>
#include <string>
#include <cctype>
#include <cmath>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");


    long double buff, sum = 0;
    int part, ex;
    bool min, exp_min;

    string s;

    cout << "Введите строку: ";
    getline(cin, s);

    int count = 0;

    while (count < s.length()) 
    {
        min = false;

        if (isdigit(s[count])) 
        {
            if (count != 0 && s[count - 1] == '-') 
            {
                buff = s[count] - '0';
                min = true;
            }
            else 
            {
                buff = s[count] - '0';
            }

            ++count;

            while (isdigit(s[count])) 
            {
                buff = buff * 10 + (s[count] - '0');
                ++count;
            }

            part = 1;

            if (s[count] == '.' && isdigit(s[count + 1]))
            {
                ++count;

                while (isdigit(s[count])) 
                {
                    part *= 10;

                    buff = buff + (long double)(s[count] - '0') / part;

                    ++count;
                }
            }

            if ((s[count] == 'e' || s[count] == 'E') && (isdigit(s[count + 1]) || (s[count + 1] == '+' && isdigit(s[count + 2])) || (s[count + 1] == '-' && isdigit(s[count + 2])))) 
            {
                exp_min = false;
                ++count;

                if (s[count] == '-') 
                {
                    exp_min = true;
                    ++count;
                }
                else if (s[count] == '+') 
                {
                    ++count;
                }

                ex = s[count] - '0';
                ++count;

                while (isdigit(s[count]))
                {
                    ex = ex * 10 + (s[count] - '0');

                    ++count;
                }

                if (exp_min)
                {
                    ex *= -1;
                }

                buff *= pow(10, ex);
            }

            if (min) 
            {
                buff *= -1;
            }

            cout << '\n' << buff;

            sum += buff;
        }
        ++count;
    }
    cout << "\n\nСумма чисел: " <<  sum << endl;

	return 0;
}