#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int N = 1e6;

ll t[4 * N];

void build(vector<ll> &a, int L, int R, int tree_index=1){
   if(L > R)  
      return;

   if(L == R){
      t[tree_index] = a[L];
      return;
   }

   int mid = (L + R) / 2;

   build(a, L, mid, tree_index * 2);
   build(a, mid + 1, R, tree_index * 2 + 1);

   t[tree_index] = max(t[tree_index * 2], t[tree_index * 2 + 1]);
}

void update(int L, int R, int pos, ll new_val, int tree_index=1){
   if(L == R){
      t[tree_index] = new_val;
      return;
   }

   int mid = (L + R) / 2;

   if(pos <= mid)
      update(L, mid, pos, new_val, tree_index * 2);
   else
      update(mid + 1, R, pos, new_val, tree_index * 2 + 1);

   t[tree_index] = max(t[tree_index * 2], t[tree_index * 2 + 1]);
}

int find(int L, int R, int l, ll val, int tree_index=1){
   
}

int main(){
   int n, m;
   cin >> n >> m;

   ll a[n];
   for(int i = 0; i < n; i++)
      cin >> a[i];

   while(m--){
      int type;
      cin >> type;

      if(type == 1){
         int pos;
         ll val;
         cin >> pos >> val;

         update(0, n - 1, pos, val);
      }
      else{
         int l;
         ll x;
         cin >> x >> l;

         cout << find(0, n - 1, l, x) << '\n';
      }
   }
}