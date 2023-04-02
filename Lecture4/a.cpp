#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
   ll n;
   ll k;
   cin >> n >> k;

   ll a[n];
   for(ll i = 0; i < n; i++){
      cin >> a[i];

   }

   for(ll i=0; i<n; i++){
      if(a[i] > k){
         cout << "Impossible";
         return 0;
      }
   }

   sort(a, a + n);

   ll cnt = 0;
   ll l = 0, r = n - 1;

   while(l <= r){
      if(a[l] + a[r] <= k){
         l++; r--;
      }
      else{
         r--;
      }

      cnt++;
   }

   cout << cnt;
}