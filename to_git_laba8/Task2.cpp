//������������ ������ � 8, ������� 2. ��������: �� ���������

/*� �������������� ��������������� ���� �������� ���������� � ��������� ������ � ������� �������� ���������� �� ��������� ������ � ��������� ���� :
���� ������, ����� ����������, ����� �����������, ����� ��������� ����.
���������� ������������� ����������� ���������� � �������������� � �������� ��������������� m ���� �� ������ N �� k - � ���� ������ � �������� ����������� ������ �� ������� t ����� ������.
������� ����� ����������� ��� ��������� � ������������� ��������� ����� � ������ ������.*/

#pragma warning(disable : 4996)

#include<iostream>
#include<string>
#include<cstdio>
using namespace std;

struct Mesta
{
    string dataviezd;
    string place;
    string time;
    int mesta;
};
Mesta* a;
void correctValue() {
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
        cout << "Enter correct value! " << endl;
    }
}
int n;
void del(Mesta arr[], int position)
{
    if (position >= n)return;
    Mesta* temp = new Mesta[n];
    for (int i = 0; i < n; i++)temp[i] = arr[i];
    delete[] arr;
    arr = new Mesta[n - 1];
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
void check(int i)
{
    cout << "check: ";
    for (int k = 0; k <= i; k++)
    {
        cout << k + 1 << ") " << "���� ������: " << a[k].dataviezd << "\n����� ��������: " << a[k].place << "\n����� ������: " << a[k].time << "\n����������� ����: " << a[k].mesta << endl;
    }
}
int main()
{
    setlocale(LC_ALL, "ru");
    cout << "���������� ���������: ";
    //freopen("file.txt", "w", stdout);

    int n, m;
    n = inputInt(0, 10);
    cout << "������� ���������� ������ ����: " << endl;

    m = inputInt(0, 100);

    cout << "������� ������ �����: " << endl;
    string city;
    cin >> city;
    cout << "������� ������ ���� ������: " << endl;
    string day;
    cin >> day;
    cout << "������� ������ �����: " << endl;
    string timme;
    cin >> timme;

    a = new Mesta[n];
    char q;
    bool fl = 0;

    for (int i = 0; i < n; i++)
    {
        cout << "�� ������ ������? (Y/N)";
        cin >> q;
        if (q != 'Y' && q != 'N')
        {
            cout << "����������� ����, �����, ����������� ���" << endl;
            continue;
        }
        if (q == 'N')
        {
            n = i + 1;
            break;
        }
        cout << "���� ������: ";
        cin >> a[i].dataviezd;
        cout << "����� ����������: ";
        cin >> a[i].place;
        cout << "����� �����������: ";
        cin >> a[i].time;
        cout << "����������� ��������� ���� ";
        cin >> a[i].mesta;
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
            cout << "����� �����, �����" << endl;
            return 0;
        }
        else
        {
            for (int i = 0; i < kk; i++)
            {
                int pos;
                cout << "������� ��������:";
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
    }
    for (int i = 0; i < n; i++)
    {
        if (m < a[i].mesta && city == a[i].place && day == a[i].dataviezd && timme > a[i].time)
        {
            cout << "���� ���������� �����." << endl;
            cout << i + 1 << ") " << "���� ������: " << a[i].dataviezd << "\n����� ��������: " << a[i].place << "\n����� ������: " << a[i].time << "\n����������� ����: " << a[i].mesta << endl;
        }
        else
        {
            cout << "��� ���������� ������ �� ������ ����� (" << i + 1 << ")" << endl;
        }
    }
}
