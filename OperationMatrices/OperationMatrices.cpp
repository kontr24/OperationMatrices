#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <stdio.h>
#include <math.h>
#include <ctime>
#include <cstdlib>
using namespace std;

void proverka()
{
	int num;
	while (true)
	{
		if (cin.good())
		{
			cin.ignore(150, '\n');
			break;
		}
		cin.clear();
		cout << "\x1b[31mОшибка. Неверный ввод данных \x1b[0m" << endl;
		cin.ignore(150, '\n');
		break;
	}
}

void MatrixA_B(int b[150][150], int a[150][150], int n, int m, int l, int p)
{
	bool z = true;
	while (z == true)
	{
		int k = 1;
		cout << "\n1.Автоматическое формирование\n2.Формирование вручную\n" << endl;
		cout << "\nНомер операции > ";
		cin >> k;
		proverka();
		if (k == 1)
		{
			z = false;
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					a[i][j] = rand() % 150;
				}
			}

			for (int i = 0; i < l; i++)
			{
				for (int j = 0; j < p; j++)
				{
					b[i][j] = rand() % 150;
				}
			}
			cout << "\nМатрица А" << endl;
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					cout << a[i][j] << "\t";
				}
				cout << endl;
			}
			cout << "\n\x1b[32mМатрица В\x1b[0m" << endl;
			HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
			for (int i = 0; i < l; i++)
			{
				for (int j = 0; j < p; j++)
				{
					SetConsoleTextAttribute(console, FOREGROUND_GREEN);
					cout << b[i][j] << "\t";
				}
				cout << endl;
			}
		}
		if (k == 2)
		{
			z = false;
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					cout << "Элемент матрицы A[" << i << "][" << j << "] = ";
					cin >> a[i][j];
					proverka();
				}
			}
			for (int i = 0; i < l; i++)
			{
				for (int j = 0; j < p; j++)
				{
					cout << "\x1b[32mЭлемент матрицы B[" << i << "][" << j << "] = \x1b[0m";
					cin >> b[i][j];
					proverka();
				}
			}
			cout << "Матрица А" << endl;
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					cout << a[i][j] << "\t";
				}
				cout << endl;
			}
			cout << "\x1b[32mМатрица В\x1b[0m" << endl;
			HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
			for (int i = 0; i < l; i++)
			{
				for (int j = 0; j < p; j++)
				{
					SetConsoleTextAttribute(console, FOREGROUND_GREEN);
					cout << b[i][j] << "\t";
				}
				cout << endl;
			}
		}
		if (k != 1 & k != 2)
		{
			cout << "\x1b[31mОшибка ввода\x1b[0m" << endl;
		}
	}


}
void Raznost(int b[150][150], int a[150][150], int c[150][150], int n, int m, int l, int p)
{
	if (n == l & m == p)
	{
		cout << "\n\x1b[34mРазность матриц А и B\x1b[0m" << endl;
		for (int i = 0; i < l; i++)
		{
			for (int j = 0; j < p; j++)
			{
				c[i][j] = a[i][j] - b[i][j];
				cout << c[i][j] << "\t";
			}
			cout << endl;
		}
	}
	else
	{
		cout << "\n\x1b[31mОшибка. Размеры матриц не совпадают\x1b[0m" << endl;
	}
}

void Summa(int b[150][150], int a[150][150], int c[150][150], int n, int m, int l, int p)
{
	if (n == l & m == p)
	{
		cout << "\n\x1b[33mСумма матриц А и B\x1b[0m" << endl;
		for (int i = 0; i < l; i++)
		{
			for (int j = 0; j < p; j++)
			{
				c[i][j] = a[i][j] + b[i][j];
				cout << c[i][j] << "\t";
			}
			cout << endl;
		}
	}
	else
	{
		cout << "\n\x1b[31mОшибка. Размеры матриц не совпадают\x1b[0m" << endl;
	}
}

void Proizvedenie(int b[150][150], int a[150][150], int n, int m, int l, int p)
{
	int c[150][150];
	if (m == l)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < l; j++)
			{
				c[i][j] = 0;
				for (int k = 0; k < p; k++)
				{
					c[i][j] += a[i][k] * b[k][j];
				}
			}
		}
		cout << "\n\x1b[35mПроизведение матриц A и B\x1b[0m" << endl;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < l; j++)
			{
				cout << c[i][j] << "\t";
			}
			cout << endl;
		}
	}
	else
		cout << "\n\x1b[31mУмножение невозможно\x1b[0m" << endl;
}

int main()
{
	setlocale(LC_ALL, "ru");
	int num = 1;
	bool vihod = false;
	int b[150][150], a[150][150], c[150][150], m, l, n, p, r = -1;
	while (!vihod)
	{
		cout << "\n\x1b[39m1.Формирование матриц A и\x1b[0m \x1b[32mB\x1b[0m\n2.Разность матриц А и \x1b[32mB\x1b[0m\n3.Умножение матриц А и \x1b[32mB\x1b[0m\n4.Сумма матриц А и \x1b[32mB\x1b[0m\n5.Очистка консоли\n6.Закрыть программу\n";
		cout << "\nНомер операции > ";
		cin >> num;
		proverka();
		switch (num) {
		case 1:
		{
			r = -1;
			while (r < 0)
			{
				cout << "Введите размер матрицы А(строки):";
				cin >> r;
				proverka();
			}
			m = -1;
			while (m < 0)
			{
				cout << "Введите размер матрицы А(столбцы):";
				cin >> m;
				proverka();
			}
			l = -1;
			while (l < 0)
			{
				cout << "\n\x1b[32mВведите размер матрицы В(строки):\x1b[0m";
				cin >> l;
				proverka();
			}
			p = -20;
			while (p < 0)
			{
				cout << "\x1b[32mВведите размер матрицы В(столбцы):\x1b[0m";
				cin >> p;
				proverka();
			}

			MatrixA_B(a, b, r, m, l, p);
			break;
		}
		case 2:
		{
			if (r == -20)
			{
				cout << "\n\x1b[31mОшибка\x1b[0m" << endl;
			}
			else
			{
				Raznost(a, b, c, r, m, l, p);
			}

			break;
		}
		case 3:
		{
			if (r == -20)
			{
				cout << "\n\x1b[31mОшибка\x1b[0m" << endl;
			}
			else
			{
				Proizvedenie(a, b, r, m, l, p);
			}

			break;
		}
		case 4:
		{
			if (r == -20)
			{
				cout << "\n\x1b[31mОшибка\x1b[0m" << endl;
			}
			else
			{
				Summa(a, b, c, r, m, l, p);
			}

			break;
		}
		case 5:
		{
			system("cls");
			cout << "\x1b[36mОтлично,консоль очищена.Работаем дальше!\x1b[0m\n";
			break;
		}
		case 6:
			vihod = true;
			break;
		}
	}
}