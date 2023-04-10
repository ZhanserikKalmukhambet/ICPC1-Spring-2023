#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int N = 1e6;

pair<ll, int> combine(pair<ll, int> a, pair<ll, int> b){
   if(a.first < b.first) return a;
   if(a.first > b.first) return b;

   return {a.first, a.second + b.second};
}

pair<ll, int> t[4 * N];

void build(vector<ll> &a, int L, int R, int tree_index=1){
   if(L > R)
      return;
   
   if(L == R){
      t[tree_index] = {a[L], 1};
      return;
   }

   int mid = (L + R) / 2;

   build(a, L, mid, tree_index * 2);
   build(a, mid + 1, R, tree_index * 2 + 1);

   t[tree_index] = combine(t[tree_index * 2], t[tree_index * 2 + 1]);
}

pair<ll, int> get_cnt_of_min(int L, int R, int l, int r,int tree_index=1){
    if(L > r || R < l)
        return {INT_MAX, 0};

    if(l <= L && R <= r)
        return t[tree_index];

    int mid = (L + R) / 2;

   pair <ll, int> t1 = get_cnt_of_min(L, mid, l, r, tree_index * 2);
   pair <ll, int> t2 = get_cnt_of_min(mid + 1, R, l, r, tree_index * 2 + 1);

    return combine(t1, t2);
}

void update(int L, int R, int pos, ll new_val, int tree_index=1){
   if(L == R){
      t[tree_index] = {new_val, 1};
      return;
   }

   int mid = (L + R) / 2;

   if(pos <= mid)
      update(L, mid, pos, new_val, tree_index * 2);
   else
      update(mid + 1, R, pos, new_val, tree_index * 2 + 1);


   t[tree_index] = combine(t[tree_index * 2], t[tree_index * 2 + 1]);
}

int main(){
   int n, m;
   cin >> n >> m;

   vector<ll> a(n);
   for(int i = 0; i < n; i++)
      cin >> a[i];

   build(a, 0, n - 1);

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
         int l, r;
         cin >> l >> r;

         pair <ll, int> temp = get_cnt_of_min(0, n - 1, l, r - 1);

         cout << temp.first << ' ' << temp.second << '\n';
      }
   }
}