//������������ 6, ������ 1. ���������: ��������� �.�.

/*������� 3.
	� ������, ��������� �� ����� ����� � ������, ���������� 
���������� �������� � ����� ������� ������.*/

#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	char row[100];
	int count = 1, group = 1;

	cout << "������� ������ �� 0 � 1: ";
	cin >> row;

	for (int i = 0; row[i] != '\0'; i++)
	{
		if (row[i] == row[i + 1])
		{
			++count;
			if (group < count)
			{
				group = count;
			}
		}
		else
		{
			count = 1;
		}
	}

	cout << "\n\n���� ������: " << row << endl;
	cout << "\n\n���-�� �������� � ����� ������� ������: " << group << endl;

	return 0;
}