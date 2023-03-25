#include <bits/stdc++.h>

using namespace std;

int main(){
   freopen("badsubs.in", "r", stdin);
   freopen("badsubs.out", "w", stdout);

   int sz = 25;
   
   int dp[sz];

   dp[0] = 1;
   dp[1] = 3;

   for(int i=2; i<sz; i++)
      dp[i] = 3*dp[i-1] - dp[i-2];
   
   int n;
   cin >> n;

   cout << dp[n];

   return 0;
}