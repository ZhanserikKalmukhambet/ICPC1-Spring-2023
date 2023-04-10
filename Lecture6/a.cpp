#include <bits/stdc++.h>

using namespace std;

int main(){
   int n;
   cin >> n;

   int a[n][n];
   for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
         cin >> a[i][j];

   int color[n];
   for(int i = 0; i < n; i++)
      cin >> color[i];

   int cnt = 0;
   for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
         if(a[i][j] == 1 && color[i] != color[j]){
            cnt++;
         }
      }
   }

   cout << cnt / 2;

   return 0;
}