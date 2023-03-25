#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define pb push_back

bool cmp(pair<pii, pii> a, pair<pii, pii> b){
   if(a.second.first == b.second.first)
      return a.second.second < b.second.second;

   return a.second.first < b.second.first;
}

int main(){
   int n;
   cin >> n;

   vector<pair<pii, pii>> v;   

   for(int i=0; i<n; i++){
      int stH, stMin, endH, endMin;

      scanf("%d:%d %d:%d", &stH, &stMin, &endH, &endMin);

      v.pb(make_pair(make_pair(stH, stMin), make_pair(endH, endMin)));
   }

   sort(v.begin(), v.end(), cmp);

   pii right = v[0].second;
   int cnt = 1;
   for(int i=1; i<n; i++){
      if(right.first == v[i].first.first){
         if(right.second <= v[i].first.second){
            right = v[i].second;
            cnt++;
         }
      }
      else if(right.first < v[i].first.first){
         right = v[i].second;
         cnt++;
      }
   }

   cout << cnt;
}