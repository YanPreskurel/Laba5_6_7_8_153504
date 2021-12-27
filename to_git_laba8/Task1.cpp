//������������ ������ � 8, ������� 1. ��������: �� ���������

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
        cout << "������� ���������� ��������! " << endl;
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

    cout << "���������� ���������: ";
    n = inputInt(0, 10);

    string s;

    char q;
    bool fl = 0;

    for (int i = 0; i < n; i++)
    {
        cout << "�������: ";
        getline(cin, a[i].surname);

        cout << "���: ";
        getline(cin, a[i].name);

        cout << "��������: ";
        getline(cin, a[i].patronymic);

        getline(cin, s);

        cout << "����� ������: ";
        cin >> a[i].number_group;

        cout << "������� ����: ";
        cin >> a[i].average_mark;

        cout << "�������: ";
        cin >> a[i].age;

        cout << "�����: ";
        cin >> a[i].income;

        if (!fl)
        {
            cout << "����� �� ������ ��������� ������ ��������? (Y/N), ���� �� ������ ������ ��������� �������� ������ (1)";
            cin >> q;
            if (q == 'Y')check(i);
            if (q == '1')fl = 1;
        }
    }

    cout << "������ ������� �������(�) �������? (Y/N)";
    cin >> q;

    if (q == 'Y')
    {
        cout << "�������? ";
        int kk;
        cin >> kk;
        if (kk >= n)
        {
            cout << "�������: " << endl;
            return 0;
        }
        else
        {
            for (int i = 0; i < kk; i++)
            {
                int pos;
                cout << "������� ��������: ";
                cin >> pos;
                del(a, pos);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (!fl)
        {
            cout << "����� �� ������ ��������� ������ ��������? (Y/N), ���� �� ������ ������ ��������� �������� ������ (1)";
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