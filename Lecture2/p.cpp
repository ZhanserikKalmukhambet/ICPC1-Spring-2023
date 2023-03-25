#include <bits/stdc++.h>

using namespace std;

int main(){
   int n;
   cin >> n;

   int a[n];
   for(int i=0; i<n; i++)
      cin >> a[i];

   int dp[n];
   for(int i=n-1; i>=0; i--){
      dp[i] = 1;
      for(int j=i+1; j<n; j++){
         if(a[i] < a[j])
            dp[i] = max(dp[i], 1 + dp[j]);
      }
   }

   int res = -1;
   for(int i=0; i<n; i++)
      res = max(res, dp[i]);

   cout << res;
}