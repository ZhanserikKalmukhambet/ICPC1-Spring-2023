#include <bits/stdc++.h>

using namespace std;

// Последовательности из 0, 1, 2 без двух единиц подряд

int main(){
   int n;
   cin >> n;

   int dp[n+1];
   dp[1] = 3;
   dp[2] = 8;

   for(int i=3; i<=n; i++)
      dp[i] = 2*dp[i-1] + 2*dp[i-2];
   
   cout << dp[n];
}