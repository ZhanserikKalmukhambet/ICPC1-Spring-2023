#include <bits/stdc++.h>

using namespace std;

int main(){
   freopen("justforfood.in", "r", stdin);
   freopen("justforfood.out", "w", stdout);

   int n, m;
   cin >> n >> m;

   long long sz = 0;

   int a[n];
   for(int i = 0; i < n; i++){
      cin >> a[i];

      sz += a[i];
   }

   sort(a, a + n);
   reverse(a, a + n);

   int cnt[sz];
   for(int i=0; i<sz; i++)
      cnt[i] = 0;
   
   for(int i = 0; i < n; i++){
      int temp = a[i];
      int ind = 0;

      while(temp != 0 && ind < sz){
         if(cnt[ind] < m){
            cnt[ind]++;
            temp--;
         }
         ind++;
      }
   }

   if(cnt[0] < m){
      cout << 0;
      return 0;
   }
   if(cnt[sz-1] == m){
      cout << sz;
      return 0;
   }

   int res = 0;
   for(int i=0; i<sz; i++){
      if(cnt[i] < m){
         res = i;
         break;
      }
   }

   cout << res;
   return 0;
}