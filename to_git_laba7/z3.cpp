//Лабораторная 7, задача 3. Выполнена: Прескурел Я.Ю.

/* Осуществить сложение чисел. Разработать функции для 
выполнения операции сложения. Предусмотреть ввод положительных и 
отрицательных чисел.
	Вариант3:  Найдите сумму двоичных чисел, заданных в естественной форме. 
	Сложение выполните в обратном коде. Ответ выразите в дополнительном коде*/

#include <iostream>
#include <string>

using namespace std;

int inputInt()
{

	double x;
	while (true)
	{
		cout << "Введите число: ";
		cin >> x;
		if (!cin.fail())
			return (int)x;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Введите корректное число: " << endl;
	}
}
string getBinarySum(string firstNumber, string secondNumber, int valueOfSystem) 
{
	string sumNumber;
	int tmp = 0;

	for (int i = 0; i < firstNumber.length(); i++)
	{
		if (findValue(firstNumber[i], valueOfSystem) + findValue(secondNumber[i], valueOfSystem) + tmp < valueOfSystem)
		{
			sumNumber.push_back(findValue((findValue(firstNumber[i], valueOfSystem) + findValue(secondNumber[i], valueOfSystem) + tmp), valueOfSystem));
			tmp = 0;
		}
		else
		{
			sumNumber.push_back(findValue(findValue(firstNumber[i], valueOfSystem) + findValue(secondNumber[i], valueOfSystem) + tmp - valueOfSystem, valueOfSystem));
			tmp = 1;
		}
	}
	if (tmp != 0)
		sumNumber.push_back(findValue(tmp, valueOfSystem));
	reverseStr(sumNumber);
	return sumNumber;
}\
string getBinaryDif(string firstNumber, string secondNumber, int valueOfSystem)
{
	int tmp = 0;
	string difNumber;

	for (int i = 0; i < firstNumber.length(); i++)
	{
		if (findValue(firstNumber[i], valueOfSystem) - findValue(secondNumber[i], valueOfSystem) > 0)
		{
			difNumber.push_back(findValue((findValue(firstNumber[i], valueOfSystem) - findValue(secondNumber[i], valueOfSystem)), valueOfSystem));
		}
		else
		{
			difNumber.push_back(findValue(findValue(firstNumber[i], valueOfSystem) - findValue(secondNumber[i], valueOfSystem) + valueOfSystem, valueOfSystem));
			firstNumber[i + 1] = findValue(findValue(firstNumber[i + 1], valueOfSystem) - 1, valueOfSystem);
		}
	}
	reverseStr(difNumber);

	return difNumber;
}
int convertToDecimal(string str, int valueOfOtherSystem) 
{
	int number = 0;
	for (int i = str.length() - 1; i >= 0; i--)
	{
		number += (findValue((char)(tolower(str[i])), valueOfOtherSystem)) * pow(valueOfOtherSystem, str.length() - 1 - i);
	}
	return number;
}
void updateStr(string& firstNumber, string& secondNumber)
{
	if (firstNumber.length() > secondNumber.length())
		for (int i = secondNumber.length(); i < firstNumber.length(); i++)
		{
			secondNumber.push_back('0');
		}
	else if (firstNumber.length() < secondNumber.length())
		for (int i = firstNumber.length(); i < secondNumber.length(); i++)
		{
			firstNumber.push_back('0');
		}
}
string binarySum(char signOfFirstNumber, string firstNumber, char signOfSecondNumber, string secondNumber, int valueOfSystem)
{

	if (convertToDecimal(firstNumber, valueOfSystem) < convertToDecimal(secondNumber, valueOfSystem)) 
	{
		std::swap(firstNumber, secondNumber);
		std::swap(signOfFirstNumber, signOfSecondNumber);
	}

	reverseStr(firstNumber);
	reverseStr(secondNumber);

	updateStr(firstNumber, secondNumber);

	if (signOfFirstNumber == '+' && signOfSecondNumber == '+')
		return signOfFirstNumber + getBinarySum(firstNumber, secondNumber, valueOfSystem);
	if (signOfFirstNumber == '-' && signOfSecondNumber == '+')
		return signOfFirstNumber + getBinaryDif(firstNumber, secondNumber, valueOfSystem);
	if (signOfFirstNumber == '+' && signOfSecondNumber == '-')
		return signOfFirstNumber + getBinaryDif(firstNumber, secondNumber, valueOfSystem);
	if (signOfFirstNumber == '-' && signOfSecondNumber == '-')
		return signOfFirstNumber + getBinarySum(firstNumber, secondNumber, valueOfSystem);
	return "I dont understand want i should to do!";
}
char findValue(int digit, int maxKey)
{
	int key[18]{ 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17 };
	char value[18]{ '0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f','g','h' };
	for (int i = 0; i < maxKey; i++)
	{
		if (key[i] == digit)
			return value[i];
	}
	return 0;
}
void reverseStr(string& str)
{
	for (int i = 0; i < str.length() / 2; i++)
	{
		char tmp = str[i];
		str[i] = str[str.length() - i - 1];
		str[str.length() - i - 1] = tmp;
	}
}
string transformNumber(string str) 
{
	string newStr;
	addZeroes(str, newStr);
	for (int i = 0; i < str.length(); i++)
	{
		newStr.push_back(str[i]);
	}
	return newStr;
}
void convertFromDecimal(int number, int valueOfOtherSystem, string& numberInAnotherSystem) 
{
	while (number != 0)
	{
		numberInAnotherSystem.push_back(findValue(number % valueOfOtherSystem, valueOfOtherSystem));
		number /= valueOfOtherSystem;
	}
	reverseStr(numberInAnotherSystem);
}
void convertBinariesInReverseCode(string& str)
{
	str = transformNumber(str);
	if (str[0] == '1') {

		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == '1')
				str[i] = '0';
			else
				str[i] = '1';
		}

	}
}
void addZeroes(string& str, string& newStr)
{
	if ((int)log2(str.length()) != log2(str.length()))
	{
		for (int i = 0; i < pow(2, (int)log2(str.length()) + 1) - str.length(); i++)
		{
			newStr.push_back('0');
		}
	}
}
string convertInReverseCode(int num) 
{
	string number;
	convertFromDecimal(num, 2, number);
	convertBinariesInReverseCode(number);
	return number;
}

int main()
{
	setlocale(LC_ALL, "rus");

	string firstNumber = convertInReverseCode(inputInt()), secondNumber = convertInReverseCode(inputInt());
	cout << firstNumber << " " << secondNumber << endl;
	cout << binarySum('+', firstNumber, '+', secondNumber, 2);

	return 0;
}