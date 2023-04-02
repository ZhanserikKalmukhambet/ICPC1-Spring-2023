#include <bits/stdc++.h>

using namespace std;

int main(){
   int n;
   cin >> n;

   int inv[n];
   for(int i = 0; i < n; i++)  
      cin >> inv[i];

   int ans[n];

   vector<int> used(n * 20, 0);

   for(int i = n - 1; i >= 0; i--){
      int cnt = 0;

      for(int j = n; j >= 1; j--){
         if(cnt == inv[i] && !used[j]){
            ans[i] = j;
            used[j] = 1;

            break;
         }

         if(!used[j]){
            cnt++;
         }
      }
   }

   for(int i=0; i<n; i++)
      cout << ans[i] << ' ';
}