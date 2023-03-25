#include <bits/stdc++.h>

using namespace std;

int main(){
   //  freopen("slalom.in", "r", stdin);
   // freopen("slalom.out", "w", stdout);

   int n;
   cin >> n;

   vector<vector<int>> a(n);

   for(int i=0; i<n; i++){
      int sz = i+1;
      vector<int> temp(sz);
      for(int j=0; j<sz; j++)
         cin >> temp[j];
      a[i] = temp;
   }

   vector<vector<int>> dp = a;
   for(int i=1; i<n; i++){
      int sz = a[i].size();

      for(int j=0; j<sz; j++){
         if(j == 0)
            dp[i][j] = a[i][j] + dp[i-1][j];
         else if(j == sz-1)
            dp[i][j] = a[i][j] + dp[i-1][sz-2];
         else
            dp[i][j] = a[i][j] + max(dp[i-1][j-1], dp[i-1][j]);
      }
   }

   int res = -100000000;
   for(int i=0; i<n; i++)
      res = max(dp[n-1][i], res);
   
   cout << res;

   // for(int i=0; i<n; i++){
   //    int sz = a[i].size();

   //    for(int j=0; j<sz; j++){
   //       cout << dp[i][j] << ' ';
   //    }
   //    cout << '\n';
   // }

   return 0;
}