//Лабораторная 7, задача 8. Выполнена: Прескурел Я.Ю.

/*Брюс недавно получил работу в NEERC (Numeric Expression Engineering & 
Research Center), где изучают и строят много различных любопытных 
чисел. Его первым заданием стало исследование двудесятичных чисел.
Натуральное число называется двудесятичным, если его десятичное 
представление является суффиксом его двоичного представления; и 
двоичное и десятичное представление рассматривается без ведущих 
нулей. Например, 1010 = 10102, так что 10 двудесятичное число. Числа 
101010 = 11111100102 и 4210 = 1010102 не являются двудесятичными.
Сначала Брюс хочет создать список двудесятичных чисел. Помогите 
ему найти n-ое наименьшее двудесятичное число.*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void Normalize(vector<int>& c)
{
    for (int i = 0; i < c.size() - 1; ++i)
    {
        c[i + 1] += c[i] >> 1;
        c[i] &= 1;
    }
}

void AddZero(vector<int>& c, int x) 
{
    c.resize(x + 1);
    c[x] = 0;
}

vector<int> AddNum(const vector<int>& a, const vector<int>& b, int k) 
{

    vector<int> c(max(a.size(), b.size()) + 1);

    for (int i = 0; i < c.size(); ++i) 
    {
        if (i < a.size()) 
        {
            c[i] += a[i];
        }
        if (i < b.size()) 
        {
            c[i] += b[i];
        }
    }

    Normalize(c);
    AddZero(c, k);

    return c;
}

int GetBit(const vector<int>& v, int b) 
{
    return v[b] & 1;
}

vector<int> Multiply(const vector<int>& a, int x, int k) 
{

    vector<int> b = a;
    b.push_back(0);

    for (int i = 0; i < b.size(); ++i) 
    {
        b[i] *= x;
    }

    Normalize(b);
    AddZero(b, k);

    return b;
}

void GenerateSequence(vector<int> n, const vector<vector<int>>& p, int k, int i, vector<pair<int, vector<int>> >& v) 
{

    if (i == k) 
    {
        n.resize(k + 1);
        if (GetBit(n, k)) 
        {
            v.push_back(make_pair(k, n));
        }
        return;
    }

    if (GetBit(n, i))
    {
        return;
    }

    GenerateSequence(n, p, k, i + 1, v);

    if (i)
    {
        GenerateSequence(AddNum(n, p[i], k + 1), p, k, i + 1, v);
    }
    return;
}

int main()
{
	setlocale(LC_ALL, "rus");

    int n;

    cout << "Введите число: ";
    cin >> n;

    if (n == 1) {
        cout << "1";
        return 0;
    }
    --n;

    vector<pair<int, vector<int>>> sequence;

    for (int k = 1; n / 2 >= sequence.size(); ++k) 
    {
        vector<int> a(k + 1);
        a[k] = 1;
        vector<vector<int>> b(k + 1);
        b[0].push_back(1);
        AddZero(b[0], k + 1);
        for (int i = 0; i < k; ++i)
        {
            b[i + 1] = Multiply(b[i], 10, k + 1);
        }
        GenerateSequence(a, b, k, 0, sequence);
    }

    for (int i = 0; i < sequence.size(); ++i) 
    {
        reverse(sequence[i].second.begin(), sequence[i].second.end());
    }
    sort(sequence.begin(), sequence.end());
    --n;
    vector<int> answer = sequence[n / 2].second;
    reverse(answer.begin(), answer.end());
    if (n % 2) {
        answer[0] ^= 1;
    }
    for (int k = sequence[n / 2].first; k >= 0; --k) 
    {
        cout << GetBit(answer, k);
    }
	return 0;
}