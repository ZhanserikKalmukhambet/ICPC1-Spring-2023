#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve(){
   int n;
   ll cash;
   cin >> n >> cash;

   vector<pair<ll, ll>> a(n);

   for(int i=0; i<n; i++)
      cin >> a[i].second;
   for(int i=0; i<n; i++){
      ll x;
      cin >> x;
      a[i].first = abs(a[i].second - x);
   }

   sort(a.begin(), a.end());

   int cnt = 0;
   for(int i=0; i<n; i++){
      ll cost = a[i].second;
      ll diff = a[i].first;

      if(cash >= cost){
         ll temp = (cash - cost) / diff;

         cnt += temp;
         cash -= temp * diff;

         cnt++;
         cash -= diff;
      }
   }

   cout << cnt << '\n';
}

int main(){
   int t;
   cin >> t;

   while(t--){
      solve();
   }
}