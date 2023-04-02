#include <bits/stdc++.h>

using namespace std;

const int sz = 1e6; 
int t[4 * sz];

void build(vector<int> &v, int L, int R, int tree_index=1) { 
    if (L > R)
        return; 
   
    if(L == R) { 
        t[tree_index] = v[L]; 
        return; 
    } 
    
    int middle = (L + R) / 2; 

    build(v, L, middle, tree_index * 2); 
    build(v, middle + 1, R, tree_index * 2 + 1);

    t[tree_index] = t[tree_index * 2] + t[tree_index * 2 + 1]; 
} 

int get_sum(int L, int R, int l, int r,int tree_index=1){
    if(L > r || R < l)
        return 0;

    if(l <= L && R <= r)
        return t[tree_index];

    int mid = (L + R) / 2;

    int ans = get_sum(L, mid, l, r, tree_index * 2) + get_sum(mid + 1, R, l, r, tree_index * 2 + 1);

    return ans;
}

void update(int L, int R, int pos, int new_val, int tree_index=1){
   if(L == R){
      t[tree_index] = new_val;
      return;
   }

   int mid = (L + R) / 2;

   if(pos <= mid)
      update(L, mid, pos, new_val, tree_index * 2);
   else
      update(mid + 1, R, pos, new_val, tree_index * 2 + 1);

   t[tree_index] = t[tree_index * 2] + t[tree_index * 2 + 1];
}

int main(){
   int n, q;
   cin >> n >> q;

   vector<int> a(n);
   for(int i = 0; i < n; i++)
      cin >> a[i];

   build(a, 0, n - 1);

   while(q--){

      char c;
      cin >> c;

      if(c == '?'){
         int l, r;
         cin >> l >> r;

         l--; r--;

         cout << get_sum(0, n - 1, l, r) << '\n';         
      }
      else{
         int pos, val;
         cin >> pos >> val;

         pos--;

         update(0, n - 1, pos ,val);
      }
   }
}