#include <stdio.h>
#include <stdlib.h> 
#include <iostream> 
using namespace std;

void qwerty(int* p, int m, int x, int y,int n)
{
  if (x+1 <= n) {
    if (y <= m[x+1]) {
      p[x+1][y]--;
    }
  }
 
}

bool check (int** p)
{
  int summ;
  for (int i=0; i!=n; i++){
    for (int j=0; j!=m[i]; j++) {
      summ+=p[i][j];
    }
  }

  if (summ == 0) {
    std:cout<<"Victory";
    return true;
  }

  return false;
}

int main()
{
    char input;
    int n, x, y, summ;

    cin>>n;

    int** p = (int**)malloc(n*sizeof(int*));
    int* m = (int*)malloc(n*sizeof(int));

    for (int i=0; i!=n; i++) {
    cin>>m[i];
      p[i] = (int*)malloc(m[i]*sizeof(int));
      for (int j=0; j!=m[i]; j++) {
        cin>>p[i][j];
      }
    }

    cout<<"\n";
    for (int i=0; i!=n; i++){
      for (int j=0; j!=m[i]; j++) {
          cout<<p[i][j]<<" ";
      }
      cout<<"\n";
    }

    cin>>x>>y;

    if (!check(p) || n==3)
    while (!check(p)) {
      cin >> input;

      switch(input) {
      case 'D': {
        y++;
        break;
      }
      case 'L': {
        x--;
        break;
      }
      case 'Q': {
        goto L;
      }
      }

      if (!(qwerty(p,m,x,y)) cout<<"Loose";
    }

    L:
    for (int i=0; i!=n; i++) {
        free(p[i]);
    }
    free(p);
    free(m);

    return 0;
}
