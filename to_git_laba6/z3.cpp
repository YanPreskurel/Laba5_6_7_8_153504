//������������ 6, ������ 3. ���������: ��������� �.�.

/*������� 3.
	  �������� ���������, �������, ���������� ������, ��������� �� 
�����, ������� �� ����� ���������� ���� ��������, �������� � �������� 
����. ����������� ������� ������ �� �������� �� ������������.*/

#include <iostream>
#include <string>
#include<regex>
#include <Windows.h>

using namespace std;

void checkGender(const string& text, const int& position)
{
	if (text[position] == '�' || text[position] == '�' || text[position] == '�' || text[position] == '�')
	{
		cout << " - ����� �������� ����" << endl;
	}
	else if (text[position] == '�' || text[position] == '�' )
	{
		cout << " - ����� �������� ����" << endl;
	}
	else
	{
		cout << " - ����� �������� ����" << endl;
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "rus");


	string text;
	getline(cin, text);

	for (int i = 0; i < text.length(); i++)
	{
		cout << text[i];

		if (text[i] == ' ' && i != 0)
		{
			checkGender(text, i - 1);
		}		
		if (i == text.length() - 1)
		{
			checkGender(text, i);
		}
	}
	return 0;
}