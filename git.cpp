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

	if (summ == 0) {
	std:cout << "Victory";
		return true;
	}

	return false;
}



int main()
{
	char input;
	int n, x, y, summ;

	cin >> n;

	int** p = (int**)malloc(n * sizeof(int*));
	int* m = (int*)malloc(n * sizeof(int));

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
		}
		cout << "\n";
	}

	cin >> x >> y;





	
	if (!check(p,n,m) || n == 3)
		while (!check(p,n,m)) {
			cin >> input;

			switch (input) {
			case 'D': {
				x++;
				p[x + 1][y]--;
				p[x - 1][y]--;
				p[x][y + 1]--;
				p[x][y - 1]--;
				p[x][y]--;
				cout << "\n";
				break;
			}
			case 'U': {
				x--;
				p[x + 1][y]--;
				p[x - 1][y]--;
				p[x][y + 1]--;
				p[x][y - 1]--;
				p[x][y]--;
				cout << "\n";
				break;
			}
			case 'L': {
				y--;
				p[x + 1][y]--;
				p[x - 1][y]--;
				p[x][y + 1]--;
				p[x][y - 1]--;
				p[x][y]--;
				cout << "\n";
				break;
			}
			case 'R': {
				y++;
				p[x + 1][y]--;
				p[x - 1][y]--;
				p[x][y + 1]--;
				p[x][y - 1]--;
				p[x][y]--;
				cout << "\n";
				break;
			}
			case 'S': {
			//	cout << "\n";
				for (int i = 0; i != n; i++) {
					for (int j = 0; j != m[i]; j++) {
						if (p[i][j] > 0) {
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

			case 'Y': { // for testing
			//	cout << x << " " << y; // show position
			//	cout << "\n";
				break;
			}

			case 'Q': {
				goto L;
			}
			}

			if (!(check(p, n, m))) cout << "Loose"; // хуй знает что это
		}
	
L:
	for (int i = 0; i != n; i++) {
		free(p[i]);
	}
	free(p);
		free(m);

		return 0;
}
