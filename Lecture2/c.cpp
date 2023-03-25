#include <bits/stdc++.h>

using namespace std;

#define mp make_pair

int main(){
   int n, m;
   cin >> n >> m;

   int dp[n+1][m+1];
   for(int i=0; i<=n; i++)
      for(int j=0; j<=m; j++)
         dp[i][j] = 0;
   
   dp[1][1] = 1;
   for(int i=2; i<=n; i++)
      for(int j=2; j<=m; j++)
         dp[i][j] = dp[i-1][j-2] + dp[i-2][j-1];
   
   cout << dp[n][m];

   return 0;
}