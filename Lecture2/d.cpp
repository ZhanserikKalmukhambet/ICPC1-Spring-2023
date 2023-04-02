#include <bits/stdc++.h>

using namespace std;

int main(){
   // freopen("king2.in", "r", stdin);
   // freopen("king2.out", "w", stdout);

   int n = 8;

   int a[n][n];
   int dp[n][n];

   for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
         cin >> a[i][j];

   for(int i = 0; i < n; i++){
      for(int j = n - 1; j >= 0; j--){
         if(i == 0 && j == n - 1)
            dp[i][j] = a[i][j];
         else if(i == 0)
            dp[i][j] = a[i][j] + dp[i][j + 1];
         else if(j == n - 1)
            dp[i][j] = a[i][j] + dp[i - 1][j];
         else
            dp[i][j] = a[i][j] + min(dp[i - 1][j + 1], min(dp[i - 1][j], dp[i][j + 1]));
      }
   }

   // for(int i=0; i<n; i++){
   //    for(int j=0; j<n; j++)
   //       cout << dp[i][j] << ' ';
   //    cout << '\n';
   // }  

   cout << dp[n-1][0];

   return 0;  
}