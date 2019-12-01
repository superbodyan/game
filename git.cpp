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
			if (p2[i][j] > 0) {
				sum2 = sum2 + p2[i][j];
			}
		}

	}
	return sum2;
}

void calculate(int x2, int y2, int **p2, int n2)
{
	p2[x2 + 1][y2]--;
	p2[x2 - 1][y2]--;
	p2[x2][y2 + 1]--;
	p2[x2][y2 - 1]--;
	p2[x2][y2]--;
}



int main()
{
	char input;
	int n, x, y, summ;
	int win = 0;

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





	
	if (!check(p,n,m) || n == 3)
		while (!check(p,n,m)) {
			cin >> input;

			switch (input) {
			case 'D': {

				calculate(x,y,p,n); 
				win = array_sum(n, p, m);
				summ = summ + win;
				x++;
				cout << "\n";
				break;
			}
			case 'U': {
				calculate(x, y, p, n);
				x--;
				cout << "\n";
				break;
			}
			case 'L': {
				calculate(x, y, p, n);
				y--;
				cout << "\n";
				break;
			}
			case 'R': {	
				calculate(x, y, p, n);
				y++;
				cout << "\n";
				break;
			}
			case 'O': {
				
				cout << summ;
				summ = 0;
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
				p[x + 1][y]--;
				p[x - 1][y]--;
				p[x][y + 1]--;
				p[x][y - 1]--;
				cout << "\n";
			}

			case 'P': { // for testing
				cout << x << " " << y; // show position
				cout << "\n";
				
				

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
