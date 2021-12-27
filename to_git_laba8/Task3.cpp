//������������ ������ � 8, ������� 3. ��������: �� ���������

/*���������� � ����������� �������� ���,
���� ������ �� �����������. ������� ���������� � ���� ����������� �����������,
�������� �� ������ ������� ����� ������. (������ ���������� ��
�����������).*/

#include <iostream>
#include <algorithm>
#pragma warning(disable : 4996)

using namespace std;

struct Reis
{
    int num;
    string type;
    string kyda;
    string otpr;
    string prib;
};

class  Participant {
public:
    string num;
    string type;
    string kyda;
    int otpr;
    int prib;
private:
    string x;

    Participant(string c, string t, string l, int n, int a, double h, int w)
    {
        num = c;
        type = t;
        kyda = l;
        otpr = n;
        prib = a;
    }
};

int main(string[]) {
    setlocale(LC_ALL, "ru");
    cout << " ����� ���������� ���������, ����� ������, �� ������ ������? (Y/N), ����� ��������, ��� ��������, ���� ����? \n����� �����������, ����� ��������, ����� �� ������ ��������� ������ ��������? (Y/N), ���� �� ������ ������ ��������� \n�������� ������ (1), ������ ������� �������(�) �������? (Y/N), ����� �� ������ ��������� ������ ��������? (Y/N), ���� �� ������ ������ ��������� �������� ������ (1).\n";
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    string time;
    cin >> time;
    Reis* a;
    a = new Reis[n];
    char q;
    for (int i = 0; i < n; i++)
    {
        cout << "�� ������ ������? (Y/N)";
        cin >> q;
        if (q == 'N')
        {
            break;
        }
        cin >> a[i].num;
        cin >> a[i].type;
        cin >> a[i].kyda;
        cin >> a[i].otpr;
        cin >> a[i].prib;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i].otpr < a[j].otpr)
            {
                swap(a[i], a[j]);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (time < a[i].otpr)
        {
            cout << i + 1 << ") " << a[i].num << endl << a[i].type << endl << a[i].otpr << endl << a[i].prib << endl;
        }
    }
}