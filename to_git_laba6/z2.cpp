//������������ 6, ������ 2. ���������: ��������� �.�.

/*������� 3.
	 � ������ ������ ����� �������� �� ������� � ��������.*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	int digit[1000];
	string row;

	cout << "������� �����: ";
	getline(cin, row);

	char alphabet[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
	char Alphabet[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
	
	for (int i = 0; row[i] != '\0'; i++)
	{
		for (int k = 0; k < 26; k++)
		{
			if (row[i] == alphabet[k] || row[i] == Alphabet[k])
			{
				digit[i] = k + 1;
			}
			else if (row[i] == ' ')
			{
				digit[i] = 32;
			}
			else if (row[i] == '\0')
			{
				digit[i] = '\0';
			}
		}
	}
	cout << "\n\n������������� ������ - ";

	for (int i = 0; row[i] != '\0'; i++)
	{
		if (digit[i] == 32)
		{
			cout << " ";
		}
		else
		{
			cout << digit[i];
		}
	}
	cout << endl;

	return 0;
}