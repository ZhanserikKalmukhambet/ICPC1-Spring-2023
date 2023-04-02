#include <bits/stdc++.h>

using namespace std;

int main(){
   freopen("lepus.in", "r", stdin);
   freopen("lepus.out", "w", stdout);

   int n;
   string s;
   cin >> n >> s;

   int dp[n];

   dp[0] = 0;
   for(int i = 1; i < n; i++){
      if(s[i] == 'w')
         dp[i] = -1;
      else{
         int x = -1, y = -1, z = -1;
         if(i-1 >= 0)
            x = dp[i - 1];
         if(i-3 >= 0)
            y = dp[i - 3];
         if(i-5 >= 0)
            z = dp[i - 5];

         dp[i] = max(x, max(y, z));

         if(s[i] == '"' && dp[i] != -1)
            dp[i]++;

      }
   }  

   // for(int i=0; i<n; i++)
   //    cout << dp[i] << ' ';

   cout << dp[n-1];

   return 0;
}