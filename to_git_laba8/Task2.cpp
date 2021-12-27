//Лабораторная работа № 8, задание 2. Выполнял: Ян Прескурел

/*У администратора железнодорожных касс хранится информация о свободных местах в поездах дальнего следования на ближайшую неделю в следующем виде :
дата выезда, пункт назначения, время отправления, число свободных мест.
Оргкомитет международной конференции обращается к администратору с просьбой зарезервировать m мест до города N на k - й день недели с временем отправления поезда не позднее t часов вечера.
Вывести время отправления или сообщение о невозможности выполнить заказ в полном объеме.*/

#pragma warning(disable : 4996)

#include<iostream>
#include<string>
#include<cstdio>
using namespace std;

struct Mesta
{
    string dataviezd;
    string place;
    string time;
    int mesta;
};
Mesta* a;
void correctValue() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int inputInt(int minValue, int maxValue)
{
    double x;
    while (true)
    {
        cin >> x;
        if (!cin.fail() && x > minValue && x < maxValue)
        {
            correctValue();
            return x;
        }
        correctValue();
        cout << "Enter correct value! " << endl;
    }
}
int n;
void del(Mesta arr[], int position)
{
    if (position >= n)return;
    Mesta* temp = new Mesta[n];
    for (int i = 0; i < n; i++)temp[i] = arr[i];
    delete[] arr;
    arr = new Mesta[n - 1];
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (i != position)
        {
            arr[j] = temp[i];
            j++;
        }
    }
}
void check(int i)
{
    cout << "check: ";
    for (int k = 0; k <= i; k++)
    {
        cout << k + 1 << ") " << "Дата выезда: " << a[k].dataviezd << "\nМесто прибытия: " << a[k].place << "\nВремя выезда: " << a[k].time << "\nКолличество мест: " << a[k].mesta << endl;
    }
}
int main()
{
    setlocale(LC_ALL, "ru");
    cout << "Количество маршрутов: ";
    //freopen("file.txt", "w", stdout);

    int n, m;
    n = inputInt(0, 10);
    cout << "Введите количество нужных мест: " << endl;

    m = inputInt(0, 100);

    cout << "Введите нужный город: " << endl;
    string city;
    cin >> city;
    cout << "Введите нужный день недели: " << endl;
    string day;
    cin >> day;
    cout << "Введите нужное время: " << endl;
    string timme;
    cin >> timme;

    a = new Mesta[n];
    char q;
    bool fl = 0;

    for (int i = 0; i < n; i++)
    {
        cout << "Ты хочешь дальше? (Y/N)";
        cin >> q;
        if (q != 'Y' && q != 'N')
        {
            cout << "Неправильно ввел, малыш, пропускаешь ход" << endl;
            continue;
        }
        if (q == 'N')
        {
            n = i + 1;
            break;
        }
        cout << "Дата выезда: ";
        cin >> a[i].dataviezd;
        cout << "Пункт назначения: ";
        cin >> a[i].place;
        cout << "Время отправления: ";
        cin >> a[i].time;
        cout << "Колличество свободных мест ";
        cin >> a[i].mesta;
        if (!fl)
        {
            cout << "Может ты хочешь проверить массив структур? (Y/N), если не хочешь больше проверять струкуры напиши (1)";
            cin >> q;
            if (q == 'Y')check(i);
            if (q == '1')fl = 1;
        }
    }
    cout << "Хочешь удалить элемент(ы) массива? (Y/N)";
    cin >> q;
    if (q == 'Y')
    {
        cout << "Сколько? ";
        int kk;
        cin >> kk;
        if (kk >= n)
        {
            cout << "Пошёл нахуй, БЫДЛО" << endl;
            return 0;
        }
        else
        {
            for (int i = 0; i < kk; i++)
            {
                int pos;
                cout << "Позиция удаления:";
                cin >> pos;
                del(a, pos);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (!fl)
        {
            cout << "Может ты хочешь проверить массив структур? (Y/N), если не хочешь больше проверять струкуры напиши (1)";
            cin >> q;
            if (q == 'Y')check(n - 1);
            if (q == '1')fl = 1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (m < a[i].mesta && city == a[i].place && day == a[i].dataviezd && timme > a[i].time)
        {
            cout << "Есть подходящие рейсы." << endl;
            cout << i + 1 << ") " << "Дата выезда: " << a[i].dataviezd << "\nМесто прибытия: " << a[i].place << "\nВремя выезда: " << a[i].time << "\nКолличество мест: " << a[i].mesta << endl;
        }
        else
        {
            cout << "Нет подходящих рейсов по данный номер (" << i + 1 << ")" << endl;
        }
    }
}
