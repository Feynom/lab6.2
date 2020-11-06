﻿#include <iostream>
#include <Windows.h>
#include <time.h>

using namespace std;

void search(int a[], const int SIZE);
void neparni(int a[], const int SIZE);
int search_r(int a[], const int SIZE, int i, int min);
void neparni_r(int a[], const int SIZE);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    srand((unsigned)time(NULL));

    int SIZE;
    cout << "Введіть розмір масиву a[]:"; cin >> SIZE;
    int* a = new int[SIZE];

    cout << "a[] = ";
    for (int i = 0; i < SIZE; i++)
    {
        a[i] = rand() % SIZE;
        cout << a[i] << " ";
    }
    cout << "\nНепарні числа(для перевірки): ";
    neparni(a, SIZE);
    cout << "\nІтераційний спосіб:" << endl;
    search(a, SIZE);
    cout << "\nРекурсивний спосіб:" << endl; cout << endl;
    cout << "Непарні числа(для перевірки): ";
    neparni_r(a, SIZE - 1);
    cout << endl;
    cout << "Значення індексів:";
    cout << search_r(a, SIZE, 0, a[0]);

    delete[]a;
    return 0;
}
//ітераційний спосіб
void search(int a[], const int SIZE)
{
    cout << "Значення індексів:";
    int min = a[0];
    for (int i = 1; i < SIZE; i++)
        if (a[i] % 2 != 0)
            if (a[i] < min)
            {
                min = a[i];
                cout << i << " ";
            }
    cout << "\nМінімальне число:" << min << endl;
}
void neparni(int a[], const int SIZE)
{
    for (int i = 0; i < SIZE; i++)
    {
        if (a[i] % 2 != 0)
            cout << a[i] << " ";
    }
}
//рекурсивний спосіб
int search_r(int a[], const int SIZE, int i, int min)
{
    if (a[i] % 2 != 0)
    {
        if (a[i] < min)
        {
            min = a[i];
            cout << i << " ";
        }
    }
    if (i < SIZE - 1)
        return search_r(a, SIZE, i + 1, min);
    else
    {
        cout << "\nМінімальне число:";
        return min;
    }
        
}
void neparni_r(int a[], const int SIZE)
{
    if (a[SIZE] % 2 != 0)
            cout << a[SIZE] << " ";
    if(SIZE > 0)
        return neparni_r(a, SIZE - 1);
}
