#include <bits/stdc++.h>

using namespace std;

const int N = 125;
int a[N];

void generate(){
   for(int i=1; i<N; i++){
      a[i] = i;
      if(i != 1)
         a[i] += a[i-1];
   }
   for(int i=2; i<N; i++)
      a[i] += a[i-1];
}

int main(){
   generate();

   int sz = 300001;
   vector<int> dp(sz, sz);

   dp[0] = 0;

   for(int i=1; i<sz; i++){
      for(int j=1; j<N; j++){
         int c = a[j];

         if(i - c >= 0)
            dp[i] = min(dp[i], 1 + dp[i - c]);
         else
            break;
      }
   }

   int t;
   cin >> t;

   while(t--){
      int n;
      cin >> n;

      cout << dp[n] << '\n';
   }
}