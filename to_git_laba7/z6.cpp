//������������ 7, ������ 6. ���������: ��������� �.�.

#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

    long long int t;

    cout << "������� ���-�� �������: ";
    cin >> t;

    while (t--)
    {
        long long int x;

        cout << "\n������� �����: ";
        cin >> x;

        cout << "\n" << (x + 1) / 10 << endl;
    }
	return 0;
}