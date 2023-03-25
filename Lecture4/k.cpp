#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
   freopen("justforfood.in", "r", stdin);
   freopen("justforfood.out", "w", stdout);

   ll n, k;
   cin >> n >> k; 

   vector<ll> a(n);
   ll sz = 0;

   for(ll i=0; i<n; i++){
      cin >> a[i];
      sz += a[i];
   }

    if(k == 0){
      cout << 0;
      return 0;
   }

    sort(a.rbegin(), a.rend());
   
   vector <ll> cnt(sz, 0);
   for(ll i = 0; i < n; i++){
      ll x = a[i];
      ll ind = 0;

      while(x != 0){
         if(cnt[ind] < k){
            cnt[ind]++;
            x--;
         }
         ind++;
      }
   }

   // for(int i=0; i<sz; i++)
   //    cout << cnt[i] << ' ';

   ll res = -1;
   for(ll i=0; i<sz; i++){
      if(cnt[i] < k){
         res = i;
         break;
      }
   }  

   if(res == -1)
      res = sz;
   
   cout << res;
   return 0;
}