#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;

void main()
{
    srand(time(0));
    setlocale(LC_ALL, "Russian");
    int m, n;
    int** mas;
    cout << "Введите количество строк матрицы ";
    cin >> n;
    cout << "Введите количество столбцов матрицы ";
    cin >> m;
    mas = new int* [n];
    cout << "Исходный массив:" << endl;
    for (int j = 0; j < n; j++)
        mas[j] = new int[m];
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++)
        {
            mas[i][j] = -100 + rand() % 201;
            cout << setw(4) << mas[i][j];
        }
        cout << endl;
    }
    cout << "Отсортироваанный массив:" << endl;
    int b;
    for (int i = 0; i < n; i++)
    {
        for (int s = 0; s < m - 1; s++)
        for (int j = 0; j < m-1; j++)
        {
            if (mas[i][j] >= 0)
            {
                int w = j + 1;
                while (w < m) {
                    if (mas[i][w] >= 0) break;
                    else w++;
                }
                if (mas[i][j] < mas[i][w])
                {
                    b = mas[i][j];
                    mas[i][j] = mas[i][w];
                    mas[i][w] = b;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << setw(4) << mas[i][j];
        }
        cout << endl;
    }
        delete [] mas;
}