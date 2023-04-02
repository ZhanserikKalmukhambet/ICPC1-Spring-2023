#include <bits/stdc++.h>

using namespace std;

const int N = 1e6;

int t[N * 4];

void build(vector<int> &a, int L, int R, int tree_index=1){
   if(L > R)
      return;
   
   if(L == R){
      t[tree_index] = a[L];
      return;
   }

   int mid = (L + R) / 2;

   build(a, L, mid, tree_index * 2);
   build(a, mid + 1, R, tree_index * 2 + 1); 

   t[tree_index] = min(t[tree_index * 2], t[tree_index * 2 + 1]);
}

int get_min(int L, int R, int l, int r, int tree_index=1){
   if(L > r || R < l)
      return 1e9;

   if(l <= L && R <= r)
      return t[tree_index];

   int mid = (L + R) / 2;

   int ans = min(get_min(L, mid, l, r, tree_index * 2), get_min(mid + 1, R, l, r, tree_index * 2 + 1));

   return ans;
}

int main(){
   // freopen("stupid_rmq.in", "r", stdin);
   // freopen("stupid_rmq.out", "w", stdout);
   
   int n;
   cin >> n;

   vector <int> a(n);
   for(int i = 0; i < n; i++)
      cin >> a[i];

   build(a, 0, n - 1);

   int t;
   cin >> t;

   while(t--){
      int l, r;
      cin >> l >> r;

      l--; r--;

      cout << get_min(0, n - 1, l, r) << '\n';
   }
}