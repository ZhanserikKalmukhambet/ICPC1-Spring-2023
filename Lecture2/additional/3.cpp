#include <bits/stdc++.h>

using namespace std;

// Последовательности из 0, 1 и 2 без двух единиц и двоек подряд

int main(){ // wrong answer
   int n;
   cin >> n;

   int dp[n+1];
   dp[1] = 3;
   dp[2] = 7;

   for(int i=3; i<=n; i++)
      dp[i] = dp[i-1] + 4*dp[i-2] - 2;

   cout << dp[n];

   return 0;
}