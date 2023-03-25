#include <bits/stdc++.h>

using namespace std;

#define ll long long

bool cmp(pair<ll, ll> a, pair<ll, ll> b){
   return a.second < b.second;
}

int main(){
   int n;
   cin >> n;

   vector<pair<ll, ll>> v;
   for(int i=0; i<n; i++){
      ll l, r;
      cin >> l >> r;

      v.push_back(make_pair(l, r));
   }

   sort(v.begin(), v.end(), cmp);

   ll right = v[0].second;
   int cnt = 1;
   for(int i=1; i<n; i++){
      if(right <= v[i].first){
         right = v[i].second;
         cnt++;
      }
   }

   cout << cnt;
}