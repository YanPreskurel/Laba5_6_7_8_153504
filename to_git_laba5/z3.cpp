//������������ 5, ������ 3. ���������: ��������� �.�.

/*��� ��������� ������������ ������ ����� ����� � ������������ n * k . 
����������� ������� (n = 5, k = 6) ������ � ����������. �������� ��������� ������� 
������ � ����������. ������� ������������ ������ �� ���������, ������������� �� 
������� ��������� ������� � ������� ������ ��������. ��������� ������������ 
��������� ������������� �������. ��������� ������ � ��������� ������������
������� �� �����. ������������ �������*/

#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	int N, M, k = 0, dif = 0, com = 1;

	cout << "������� ������ ������� NxM: ";
	cin >> N >> M;
	while (!(cin >> N) || (cin.peek() != '\n') || N < 1)
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "\n��������� ������" << endl;
		cout << "\n������� ������ ������� NxM: ";
	}
	while (!(cin >> M) || (cin.peek() != '\n') || M < 1)
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "\n��������� ������" << endl;
		cout << "\n������� ������ ������� NxM:";
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

	cout << "\n\n";

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << arr[i][j] << '\t';
		}
		cout << "\n\n";
	}

	int* arr2 = new int[N - dif];

	for (int i = 0, j = 0; i < N; i++, j++)
	{
		if (arr[i][j] % 2 == 0)
		{
			arr2[k] = arr[i][j];
			k++;
		}
		else
		{
			dif++;
		}
	}

	for (int i = 0; i < N - dif; i++)
	{
		com *= arr2[i];
	}

	cout << "��������� ������:\n";
	for (int i = 0; i < N - dif; i++)
	{
		cout << arr2[i] << '\t';
	}

	cout << "\n\n������������ ��������� ������� = " << com << endl;

	delete[] arr2;

	for (int i = 0; i < N; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;

	return 0;
}