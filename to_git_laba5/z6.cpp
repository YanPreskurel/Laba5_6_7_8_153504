//������������ 5, ������ 6. ���������: ��������� �.�.

/*��������� ��������� ����������� ������� F(n):

F(n) = n % 10, if(n % 10 > 0)
F(n) = 0, if(n = 0)
F(n) = F(n / 10), otherwise
��������� ������� S (p, q) ��������� �������:
S (p, q) = c���� F(i), ����� i = p, �� ���� ���� �� ������ i = q
�� �������� p � q ���������� ��������� S (p, q).*/

#include <iostream>

using namespace std;

int Recursive_func(int i)
{
	if (i % 10 > 0)
	{
		return i % 10;
	}
	else if (i == 0)
	{
		return 0;
	}
	else
	{
		return Recursive_func(Recursive_func(i / 10));
	}
}

int S(int p, int q)
{
	int sum = 0;

	for (int i = p; i < q + 1; i++)
	{
		sum += Recursive_func(i);
	}

	return sum;
}

int main()
{
	setlocale(LC_ALL, "rus");

	int p, q;

	cout << "������� �������� p � q: ";
	while (!(cin >> p) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "\n��������� ������" << endl;
		cout << "\n������� �������� p � q: ";
	}
	while (!(cin >> q) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "\n��������� ������" << endl;
		cout << "\n������� �������� p � q:  ";
	}

	cout << "\n\n����� = " << S(p, q) << endl;
	

	return 0;
}