//������������ 5, ������ 2. ���������: ��������� �.�.

/*������� 3.
	��� ��������� ����������� ������� B �� N ��������� ����� ������������ 
����������, ����������� �� ������� B(i)^2 + cos B(i). ����������� ������� 
��������� ������ ��� �������� ��� ������ �� ������� �������. ����������� ������ 
�����������, ����� ��������� ������ ���� �������.*/

#include <iostream>
#include <iomanip>
#include <Windows.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	HINSTANCE load;
	load = LoadLibrary(L"DynamicLib.dll");
	typedef double (*recursive_func) (int, int, double*);

	recursive_func Recursive_func;
	Recursive_func = (recursive_func)GetProcAddress(load, "Recursive_func");

	int N;

	cout << "������� ���-�� ���������: ";
	while (!(cin >> N) || (cin.peek() != '\n') || N < 1 && N > 100)
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "\n��������� ������" << endl;
		cout << "\n������� ���-�� ���������: ";
	}

	double* arr = new double[N];

	for (int i = 0; i < N; i++)
	{
		cout << "������� [" << i << "] ������� �������: ";
		while (!(cin >> arr[i]) || (cin.peek() != '\n'))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "\n��������� ������" << endl;
			cout << "\n�������[" << i << "] ������� ������� : ";
		}
	}

	double answer = Recursive_func(N / 2, N - 1, arr) * Recursive_func(0, N / 2 - 1, arr);

	cout << "\n\n������������ ���������� = " << answer << endl;
	
	delete[] arr;
	FreeLibrary(load);

	return 0;
}