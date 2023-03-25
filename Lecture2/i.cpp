#include <bits/stdc++.h>

using namespace std;

int main(){
   int s, n;
   cin >> s >> n;

   int a[n];
   for(int i=0; i<n; i++)
      cin >> a[i];
   
   sort(a, a + n);

   int mini = a[0];

   int dp[s+1];
   for(int i=0; i<=s; i++)
      dp[i] = 0;

   for(int j=0; j<n; j++){
      int cost = a[j];

      for(int i=1; i<=s; i++){
         if(i >= cost){
            if(cost == mini)
               dp[i] = cost;
            else
               dp[i] = max(dp[i], dp[i - cost] + cost);
         }
         else
            dp[i] = max(dp[i], 0);
      }
   }

   cout << dp[s];

   return 0;
}