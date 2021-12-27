//������������ 5, ������ 5. ���������: ��������� �.�.

/*��� ��������� ������������ ������ ����� �����. �������� ��������� ������� 
������� ������ � ����������. ������� ������������ ������ �� ���������, 
������������� � ������ �������� ������� ������� � ������� �������� ��������. 
��������� ������� �������������� ��������� ������������� �������.
������� ��������� �� �����.
������������ �������*/

#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	int N, M, dif = 0, k = 0;
	double mid = 0;

	cout << "������� ������ ������� NxM: ";
	while (!(cin >> N) || (cin.peek() != '\n') || N < 1)
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "\n��������� ������" << endl;
		cout << "\n������� ������� �������� N: ";
	}
	while (!(cin >> M) || (cin.peek() != '\n') || M < 1)
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "\n��������� ������" << endl;
		cout << "\n������� ������� �������� N: ";
	}

	int** arr = new int* [N];

	for (int i = 0; i < N; i++)
	{
		arr[i] = new int[M];
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << "������� [" << i << ", " << j << "] ������� ������� ";
			while (!(cin >> arr[i][j]) || (cin.peek() != '\n'))
			{
				cin.clear();
				while (cin.get() != '\n');
				cout << "\n��������� ������" << endl;
				cout << "\n������� [" << i << ", " << j << "] ������� ������� ";
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << arr[i][j] << '\t';
		}
		cout << "\n\n";
	}

	int* arr2 = new int[M / 2 * N - dif];

	for (int i = 0; i < N; i++)
	{
		for (int j = 1; j < M; j += 2)
		{
			if (arr[i][j] % 2 != 0)
			{
				arr2[k] = arr[i][j];
				k++;
			}
			else
			{
				dif++;
			}
		}		
	}

	for (int i = 0; i < (M / 2 * N - dif); i++)
	{
		mid += arr2[i];
	}

	cout << "\n��������� ������:\n\n";

	for (int i = 0; i < (M / 2 * N - dif); i++)
	{
		cout << arr2[i] << '\t';
	}

	cout << "\n\n������� �������������� = " << mid / (M / 2 * N - dif) << '\n';

	for (int i = 0; i < N; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;

	delete[] arr2;

	return 0;
}