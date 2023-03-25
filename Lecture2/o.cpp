#include <bits/stdc++.h>

using namespace std;

// LCS - dynamic approach

int main(){
   string s, t;
   cin >> s >> t;

   int n = s.size(), m = t.size();

   int dp[n+1][m+1];

   for(int i=0; i<=n; i++)
      dp[i][0] = 0;
   for(int j=0; j<=m; j++)
      dp[0][j] = 0;
   
   for(int i=1; i<=n; i++){
      for(int j=1; j<=m; j++){
         if(s[i-1] == t[j-1])
            dp[i][j] = 1 + dp[i-1][j-1];
         else
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      }
   }

   // for(int i=1; i<=n; i++){
   //    for(int j=1; j<=m; j++)
   //       cout << dp[i][j] << ' ';
   //    cout << '\n';
   // }

   int x = n, y = m;

   string res = "";

   while(x > 0 && y > 0){
      if(s[x-1] == t[y-1]){
         res += s[x-1];
         x--; y--;
      }
      else if(dp[x-1][y] > dp[x][y-1])
         x--;
      else
         y--;
   }

   reverse(res.begin(), res.end());

   cout << res;

   return 0;
}