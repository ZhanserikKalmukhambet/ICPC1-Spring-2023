#include <bits/stdc++.h>

using namespace std;

const int sz = 1e6;

int t_max[4 * sz];
int t_min[4 * sz];

void build(vector<int>& a, int L, int R, int tree_index=1){
   if (L > R)
        return; 

   if(L == R){ 
       t_max[tree_index] = a[L]; 
       t_min[tree_index] = a[L];
       return; 
   } 
   
   int middle = (L + R) / 2; 

   build(a, L, middle, tree_index * 2); 
   build(a, middle + 1, R, tree_index * 2 + 1);

   t_max[tree_index] = max(t_max[tree_index * 2], t_max[tree_index * 2 + 1]);
   t_min[tree_index] = min(t_min[tree_index * 2], t_min[tree_index * 2 + 1]); 
}

int get_min(int L, int R, int l, int r, int tree_index=1){
   if(L > r || R < l)
      return 1e9;

   if(l <= L && R <= r)
      return t_min[tree_index];

   int mid = (L + R) / 2;

   int ans = min(get_min(L, mid, l, r, tree_index * 2), get_min(mid + 1, R, l, r, tree_index * 2 + 1));

   return ans;
}

int get_max(int L, int R, int l, int r, int tree_index=1){
   if(L > r || R < l)
      return (-1e9);

   if(l <= L && R <= r)
      return t_max[tree_index];

   int mid = (L + R) / 2;

   int ans = max(get_max(L, mid, l, r, tree_index * 2), get_max(mid + 1, R, l, r, tree_index * 2 + 1));

   return ans;
}

void update(int L, int R, int pos, int new_val, int tree_index=1){
   if(L == R){
      t_max[tree_index] = new_val;
      t_min[tree_index] = new_val;
      return;
   }

   int mid = (L + R) / 2;

   if(pos <= mid)
      update(L, mid, pos, new_val, tree_index * 2);
   else
      update(mid + 1, R, pos, new_val, tree_index * 2 + 1);

   t_max[tree_index] = max(t_max[tree_index * 2], t_max[tree_index * 2 + 1]);
   t_min[tree_index] = min(t_min[tree_index * 2], t_min[tree_index * 2 + 1]);
}

int main(){
   // freopen("rvq.in", "r", stdin);
   // freopen("rvq.out", "w", stdout);

   int n = 100100;

   vector <int> a(n);

   for(int i = 0; i < n; i++)
      a[i] = ((i + 1) * (i + 1)) % 12345 + ((i + 1) * (i + 1) * (i + 1)) % 23456;

   build(a, 0, n - 1);

   int q;
   cin >> q;
   
   while(q--){
      int l, r;
      cin >> l >> r;
      
      if(l < 0){
         l = abs(l);
         l--;

         update(0, n - 1, l, r);
      }
      else{
         l--; r--;

         cout << abs(get_max(0, n - 1, l, r) - get_min(0, n - 1, l, r)) << '\n';
      }
   }
}