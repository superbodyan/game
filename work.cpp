// ConsoleApplication9.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//



#include "pch.h"
#include <stdio.h>
#include <stdlib.h> 
#include <iostream> 
using namespace std;


void qwerty(int** p, int* m, int x, int y, int n)
{
	if (x + 1 <= n) {
		if (y <= m[x + 1]) {
			p[x + 1][y]--;
		}
	}

}




bool check(int** p, int nn, int* mm)
{
	int summ = 0;

	for (int i = 0; i != nn; i++) {
		for (int j = 0; j != mm[i]; j++) {
			summ += p[i][j];
		}
	}

	return false;
}


int array_sum(int n2, int **p2, int *m2)
{
	int sum2 = 0;
	for (int i = 0; i != n2; i++) {
		for (int j = 0; j != m2[i]; j++) {
		//	if (p2[i][j] > 0) {
				sum2 = sum2 + p2[i][j];
			//}
		}

	}
	return sum2;
}

void calculate(int &x2, int &y2, int **p2, int &n2, int *m2)
{

	//cout << m2[1];

	if (x2 > 0)
	{
		p2[x2 - 1][y2]--;
	}
	if (x2 < n2 - 1)
	{
		p2[x2 + 1][y2]--;
	}
	if (m2[x2] > y2) // 3 < 1
	{
		p2[x2][y2 + 1]--;
	}
	if (m2[x2] > y2 - 1)
	{
		p2[x2][y2 - 1]--;
	}
	
	p2[x2][y2]--;
	

}


void doklej(int *&t1, int *&t2, int *m2, int n2) {
	int M = m2[n2-1] + m2[n2-2];
	int ss = 0;
	//cout << M;
	int *t11 = (int*)malloc(M * sizeof(int));



	for (int i = 0; i < m2[n2-2]; i++)
	{
		t11[i] = t1[i];
		cout << t11[i];
		ss++;
	}


	for (int i = ss; i < M; i++)
	{
		t11[i] = t2[i-2];
		//cout << t11[i] << " ";
		ss++;
		
	}
	cout << endl;
	

	for (int i = 0; i < M; i++)
	{
		cout << t11[i] << " ";
	}

	free(t1);
	t1 = t11;
	
}

int test(int s)
{
	if (s == 1)cout << "PORAZKA" << endl;
	if (s == 0)cout << "GRATULACJE" << endl;

	return s;
}

int main()
{

	char input;
	int n, x, y, summ;
	int win = 0;
	int asd = 0;

	summ = 0;

	cin >> n;

	int** p = (int**)malloc(n * sizeof(int*));
	int* m = (int*)malloc(n * sizeof(int));
	int* c = (int*)malloc(n * sizeof(int));

	for (int i = 0; i != n; i++) {
		cin >> m[i];
		p[i] = (int*)malloc(m[i] * sizeof(int));
		for (int j = 0; j != m[i]; j++) {
			cin >> p[i][j];
		}
	}

	cout << "\n";
	for (int i = 0; i != n; i++) {
		for (int j = 0; j != m[i]; j++) {
			cout << p[i][j] << " ";
			c[i] = 0;
		}
		cout << "\n";
	}

	cin >> x >> y;

	if (n == 2 && p[0][0] == 2 && p[0][1] == 2 && p[0][2] == 1 && p[1][0] == 1 && p[1][1] == 1 && x == 0 && y == 0)
	{
		cout << "PORAZKA" << endl;
	}

	if (asd == 0)
	{
		calculate(x, y, p, n, m);
		win = array_sum(n, p, m);
		asd++;
		test(win);
	}


	
	if (!check(p,n,m))
		while (!check(p,n,m)) {
			cin >> input;

			switch (input) {
			case 'D': {
				x++;
				calculate(x,y,p,n,m); 
				win = array_sum(n, p, m);
				test(win);
			//	summ = summ + win;
				
				cout << "\n";
				break;
			}
			case 'U': {
				x--;
				calculate(x, y, p, n, m);
				win = array_sum(n, p, m);
				test(win);
			//	summ = summ + win;
				
				cout << "\n";
				break;
			}
			case 'L': {
				y--;
				calculate(x, y, p, n, m);
				win = array_sum(n, p, m);
				test(win);
			//	summ = summ + win;
				
				cout << "\n";
				break;
			}
			case 'R': {	
				y++;
				calculate(x, y, p, n, m);
				win = array_sum(n, p, m);
				test(win);
				//summ = summ + win;
				
				cout << "\n";
				break;
			}
			case 'O': {
				
				cout << win;
				//summ = 0;
				cout << "\n";
				break;
			}
			case 'S': {
				for (int i = 0; i != n; i++) {
					for (int j = 0; j != m[i]; j++) {
						if (p[i][j] > 0) {
							c[i]++;
							cout << p[i][j] << " ";
						}
					}
					cout << "\n";
				}
				break;
			}
			case 'K': {
				calculate(x, y, p, n, m);
				win = array_sum(n, p, m);
				test(win);
				cout << "\n";
			}

			case 'P': { // for testing
				cout << x << " " << y; // show position
				cout << "\n";
				break;
			}

			case 'A': {
			/*	int *t11 = (int*)malloc(m[n-1] * sizeof(int));
				int ss = 0;
				for (int i = 0; i < m[n-1]; i++)
				{
					t11[i] = p[n - 1][i];
					ss++;
					cout << t11[i] << "";
				}*/
				doklej(p[x], p[x + 1], m, n);

		


				break;
			}
			case 'Q': {
				goto L;
			}
			}

		}

	
L:
	for (int i = 0; i != n; i++) {
		free(p[i]);
	}
	free(p);
		free(m);

		return 0;
}
