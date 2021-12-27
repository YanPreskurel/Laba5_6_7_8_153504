//Лабораторная работа № 8, задание 1. Выполнял: Ян Прескурел

#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

struct Person
{
    string surname;
    string name;
    string patronymic;
    int number_group;
    double average_mark;
    int age;
    double income;
};
Person* a;
void correctValue() 
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int inputInt(int minValue, int maxValue) 
{
    double x;
    while (true)
    {
        cin >> x;
        if (!cin.fail() && x > minValue && x < maxValue) 
        {
            correctValue();
            return x;
        }
        correctValue();
        cout << "Введите корректное значение! " << endl;
    }
}
void check(int i)
{
    cout << "check: ";
    for (int k = 0; k <= i; k++)
    {
        cout << k + 1 << ") " << a[k].surname << ' ' << a[k].name << ' ' << a[k].patronymic << ' ' << a[k].number_group << ' ' << a[k].average_mark << ' ' << a[k].age << ' ' << a[k].income << endl;
    }
}
int n;
void del(Person arr[], int position)
{
    if (position >= n)return;
    Person* temp = new Person[n];
    for (int i = 0; i < n; i++)temp[i] = arr[i];
    delete[] arr;
    arr = new Person[n - 1];
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (i != position)
        {
            arr[j] = temp[i];
            j++;
        }
    }
}

void OutPut_Surname(Person* arr, int& size)
{
    double minIncome = 2 * 417.86;

    for (int i = 0; i < size; i++)
    {
        if (arr[i].income < minIncome)
        {
            cout << arr[i].surname << endl;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "ru");

    cout << "Количество студентов: ";
    n = inputInt(0, 10);

    string s;

    char q;
    bool fl = 0;

    for (int i = 0; i < n; i++)
    {
        cout << "Фамилия: ";
        getline(cin, a[i].surname);

        cout << "Имя: ";
        getline(cin, a[i].name);

        cout << "Отчество: ";
        getline(cin, a[i].patronymic);

        getline(cin, s);

        cout << "Номер группы: ";
        cin >> a[i].number_group;

        cout << "Средний балл: ";
        cin >> a[i].average_mark;

        cout << "Возраст: ";
        cin >> a[i].age;

        cout << "Доход: ";
        cin >> a[i].income;

        if (!fl)
        {
            cout << "Может ты хочешь проверить массив структур? (Y/N), если не хочешь больше проверять струкуры напиши (1)";
            cin >> q;
            if (q == 'Y')check(i);
            if (q == '1')fl = 1;
        }
    }

    cout << "Хочешь удалить элемент(ы) массива? (Y/N)";
    cin >> q;

    if (q == 'Y')
    {
        cout << "Сколько? ";
        int kk;
        cin >> kk;
        if (kk >= n)
        {
            cout << "Отстань: " << endl;
            return 0;
        }
        else
        {
            for (int i = 0; i < kk; i++)
            {
                int pos;
                cout << "Позиция удаления: ";
                cin >> pos;
                del(a, pos);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (!fl)
        {
            cout << "Может ты хочешь проверить массив структур? (Y/N), если не хочешь больше проверять струкуры напиши (1)";
            cin >> q;

            if (q == 'Y')check(n - 1);
            if (q == '1')fl = 1;
        }
        for (int j = i + 1; j < n; j++)
        {
            if (a[i].income < a[j].income)
            {
                swap(a[i], a[j]);
            }
        }
        for (int i = 0; i < n; i++)
        {
            OutPut_Surname(a, n);
        }
    }
}