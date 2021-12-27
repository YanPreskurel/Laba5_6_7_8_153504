//������������ 5, ������ 7. ���������: ��������� �.�.

/*����������� ������� ������ ��������� �������:
f(0,0) = 1
f(n,r) = ����� f(n-1, r-i), i = 0, �� ���� ���� �� ������ i = k - 1,
when [(n > 0) and (0 <= r < n * (k - 1) + 1)]
f(n,r) = 0, otherwise
��������� �������� x = ����� f(n, i) % m, ����� i = 0,
�� ���� ���� �� ������ i = n * (k - 1), ��� m = 10^t. */

#include <iostream>

using namespace std;

long long Recursion_func(unsigned long long c, unsigned long long n, unsigned long long m) //����������� �������
{
	if (n == 0)
	{
		return 1;
	}
	if (n & 1)
	{
		return c * Recursion_func(c * c % m, n / 2, m) % m;
	}
	return Recursion_func(c * c % m, n / 2, m);
}

int main()
{
	setlocale(LC_ALL, "rus");

	int count = 1; // �������
	unsigned long long int k, n, m, t, result;

	while (cout << "������� �������� ���������� k, n � t: " && cin >> k >> n >> t) // ���� ������������ �� ������ 0 0 0, 	
	{                                                                             // ��������� ����� ����������� ������
		if (k == 0 && n == 0 && t == 0)
		{
			break; // ����� �� �����
		}

		m = pow(10, t);
		unsigned long long int c = k % m; // ��������� ������ 

		result = Recursion_func(c, n, m); 

		cout << "\nCase #" << count++ << ": " << result << "\n\n"; // ����� ������
	}
	return 0;
}