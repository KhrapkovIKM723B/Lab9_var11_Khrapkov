#include <iostream>
#include <stdlib.h>
#include <cmath>
using namespace std;

const int n = 5;
const int m = 10;

bool isFibonacci(int num)
{
    int a = 0, b = 1;
    while (b < num)
    {
        int temp = b;
        b += a;
        a = temp;
    }
    return b == num || a == num;
}

void task1(int a[n][m])
{
    int sum = 0;
    int maxElements[m] = { 0 };

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 || a[i][j] > maxElements[j])
            {
                maxElements[j] = a[i][j];
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < m; j++)
            {
                sum += a[i][j];
            }
        }
    }

    cout << "Сума елементів на парних рядках: " << sum << endl;
    cout << "Чи є сума числом Фібоначчі: " << (isFibonacci(sum) ? "Так" : "Ні") << endl;
    cout << "Максимальні значення кожного стовпця: ";
    for (int j = 0; j < m; j++)
    {
        cout << maxElements[j] << " ";
    }
    cout << endl;
}

void task2(int a[n][m])
{
    int sumBelowDiagonal = 0, sumPositiveDiagonal = 0;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            sumBelowDiagonal += abs(a[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (a[i][i] > 0)
        {
            sumPositiveDiagonal += a[i][i];
        }
    }

    cout << "Сума модулів елементів нижче головної діагоналі: " << sumBelowDiagonal << endl;
    cout << "Сума додатних елементів головної діагоналі: " << sumPositiveDiagonal << endl;
    cout << "Елементи, більші за суму додатних елементів головної діагоналі:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] > sumPositiveDiagonal)
            {
                cout << "a[" << i << "][" << j << "] = " << a[i][j] << "\t";
            }
        }
    }
    cout << endl;
}

int main()
{
    int a[n][m];


    cout << "Матриця:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            a[i][j] = rand() % 100;
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }

    // Виконання першого завдання
    cout << "Виконання першого завдання:\n";
    task1(a);

    // Переініціалізація масиву для другого завдання
    cout << "\nПереініціалізація масиву для другого завдання:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            a[i][j] = rand() % 19 - 9;  // Заповнення числами від -9 до 9
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }

    // Виконання другого завдання
    cout << "Виконання другого завдання:\n";
    task2(a);

    return 0;
}
