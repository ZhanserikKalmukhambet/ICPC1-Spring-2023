#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>

int main(){
   ll t;
   cin >> t;

   while(t--){
      ll n, q;
      cin >> n >> q;

      ll a[n];
      for(ll i = 0; i < n; i++)
         cin >> a[i];

      for(ll i = 1; i < n; i++)
         a[i] += a[i - 1];

      while(q--){
         ll l, r, k;
         cin >> l >> r >> k;

         l--; r--;

         ll sum = a[r];
         if(l != 0)
            sum -= a[l - 1];

         ll temp = (r - l + 1) * k;

         if(a[n - 1] % 2 == 0){
            if((sum % 2 == 0 && temp % 2 == 1) || (sum % 2 == 1 && temp % 2 == 0))
               cout << "YES" << '\n';
            else
               cout << "NO" << '\n';
         }
         else{
            if((sum % 2 == 0 && temp % 2 == 0) || (sum % 2 == 1 && temp % 2 == 1))
               cout << "YES" << '\n';
            else
               cout << "NO" << '\n';
         }
      }
   }
}