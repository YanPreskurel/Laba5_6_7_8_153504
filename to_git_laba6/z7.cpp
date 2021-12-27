//������������ 6, ������ 7. ���������: ��������� �.�.

/*� �������� ������ S ����� ������������ �� ����� ���������, ������� 
�� �������� �����������.
������ ������� ������:
�� ���� �������� ������ S, ��������� �� �������� ���� ���������� 
�������� (1 ? |S| ? 105 ).
������ �������� ������:
�������� ���� ����� ����� � ����� ������������� ������������. 
���� ����� ��������� �� ����������, �� �������� -1*/

#include <iostream>
#include <string>
#include<Windows.h>

using namespace std;

bool eqchar(string s) // ��������, �������� �� ������ ���������� ���������� ��������
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

bool ispal(string s) // ��������, �������� �� ������ �����������
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

        cout << "������� ������: ";
        getline(cin, s);

        if (eqchar(s))
        {
            cout << -1;
        }
        else
        {
            cout << "\n\n������ ������������ ���������, ������� �� �������� �����������: ";

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