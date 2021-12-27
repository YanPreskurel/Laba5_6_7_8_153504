//������������ 5, ������ 1. ���������: ��������� �.�.

/*������� 3.
	������������ ��� ��������� ������������ �������-������� A � B
������������ n * n. ����������� �������� (n = 10) ������ � ����������.
�������� ��������� a[i][j] � b[i][j] ���������� �������� ����������.
���������� ����� ���������, ������������� �� ���������, ��� ������
��������-������. ������������ �������. ������� �� ����� ���������� 
������� � ���� ������ � �������� ����.*/
	
#include <iostream>
#include "../StaticLib(1)/StaticLib1.h"

using namespace std;

int main()
{	
	setlocale(LC_ALL, "rus");

	int N; 

	cout << "������� ������� �������� N: ";

	while (!(cin >> N) || (cin.peek() != '\n') || N < 2 && N > 100)
	{
		cin.clear();
		while (cin.get() != '\n' );
		cout << "\n��������� ������" << endl;
		cout << "\n������� ������� �������� N: ";
	}

	int** arr = new int* [N];
	int** arr2 = new int* [N];

	Create_Array2(arr, arr2, N);
	InputArray(arr, arr2, N);
	Output(arr, arr2, N);
	Desicion(arr, arr2, N);
	Delete_Array(arr, arr2, N);

	return 0;
}