#include <bits/stdc++.h>

#define INF 2000000000

using namespace std;

 

int n;

int dp[5001];

int f(int n) {

   if (n == 1) 
      return 1;

   if (dp[n] != -1) 
      return dp[n];

  int res = INF;

  for(int i = 1; i <= n / 2; i++)

    res = min(res,f(i) + f(n - i));

  for(int i = 2; i * i <= n; i++)

    if (n % i == 0) res = min(res,f(i) + f(n/i));

  return dp[n] = res;

}

 

int main(void) {

  memset(dp,-1,sizeof(dp));

  cin >> n;

   cout << f(n);

  return 0;

}