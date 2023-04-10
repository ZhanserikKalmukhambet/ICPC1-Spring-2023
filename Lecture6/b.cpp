#include <bits/stdc++.h>

using namespace std;


int a[10000][10000];

int main(){
   int n, m;
   cin >> n >> m;

   for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
         a[i][j] = 0;

   for(int i = 0; i < m; i++){
      int x, y;
      cin >> x >> y;

      x--; y--; 

      a[x][y] = 1;
   }

   for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++)
         cout << a[i][j] << ' ';

      cout << '\n';
   }
}