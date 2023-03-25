#include <bits/stdc++.h>

using namespace std;

int main(){
   int n;
   cin >> n;

   int a[n];
   for(int i=0; i<n; i++)  
      cin >> a[i];

   sort(a, a + n);

   int dp[n+1];

   dp[1] = 0;
   dp[2] = a[1] - a[0];
   dp[3] = a[2] - a[0];

   for(int i=4; i<=n; i++)
      dp[i] = (a[i-1] - a[i-2]) + min(dp[i-1], dp[i-2]);
   
   cout << dp[n];
}