#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int sz = 1e6;

ll t_max[4 * sz];
ll t_min[4 * sz];

void build(vector<ll>& a, ll L, ll R, ll tree_index=1){
   if (L > R)
        return; 

   if(L == R){ 
       t_max[tree_index] = a[L]; 
       t_min[tree_index] = a[L];
       return; 
   } 
   
   ll middle = (L + R) / 2; 

   build(a, L, middle, tree_index * 2); 
   build(a, middle + 1, R, tree_index * 2 + 1);

   t_max[tree_index] = max(t_max[tree_index * 2], t_max[tree_index * 2 + 1]);
   t_min[tree_index] = min(t_min[tree_index * 2], t_min[tree_index * 2 + 1]); 
}

ll get_min(ll L, ll R, ll l, ll r, ll tree_index=1){
   if(L > r || R < l)
      return 1e9;

   if(l <= L && R <= r)
      return t_min[tree_index];

   ll mid = (L + R) / 2;

   ll ans = min(get_min(L, mid, l, r, tree_index * 2), get_min(mid + 1, R, l, r, tree_index * 2 + 1));

   return ans;
}

ll get_max(ll L, ll R, ll l, ll r, ll tree_index=1){
   if(L > r || R < l)
      return (-1e9);

   if(l <= L && R <= r)
      return t_max[tree_index];

   ll mid = (L + R) / 2;

   ll ans = max(get_max(L, mid, l, r, tree_index * 2), get_max(mid + 1, R, l, r, tree_index * 2 + 1));

   return ans;
}

void update(ll L, ll R, ll pos, ll new_val, ll tree_index=1){
   if(L == R){
      t_max[tree_index] = new_val;
      t_min[tree_index] = new_val;
      return;
   }

   ll mid = (L + R) / 2;

   if(pos <= mid)
      update(L, mid, pos, new_val, tree_index * 2);
   else
      update(mid + 1, R, pos, new_val, tree_index * 2 + 1);

   t_max[tree_index] = max(t_max[tree_index * 2], t_max[tree_index * 2 + 1]);
   t_min[tree_index] = min(t_min[tree_index * 2], t_min[tree_index * 2 + 1]);
}

int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   // freopen("rvq.in", "r", stdin);
   // freopen("rvq.out", "w", stdout);

   ll n = 100001;

   vector <ll> a(n);

   for(ll i = 0; i < n; i++)
      a[i] = (i * i) % 12345 + (i * i * i) % 23456;

   build(a, 0, n - 1);

   ll q;
   cin >> q;
   
   while(q--){
      ll l, r;
      cin >> l >> r;
      
      if(l < 0){
         l = abs(l);

         update(0, n - 1, l, r);
      }
      else{
         cout << get_max(0, n - 1, l, r) - get_min(0, n - 1, l, r) << '\n';
      }
   }
}