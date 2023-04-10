#include <bits/stdc++.h>

using namespace std;

const int N = 1e6;

int t[4 * N];

void build(vector<int> a, int L, int R, int tree_index=1){
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

vector<int> get_frequency_array(vector<int> a, int n){
   vector <int> res(n);

   unordered_map<int, int> mp;
   for(auto val : a)
      mp[val]++;

   for(int i = 0; i < n; i++)
      res[i] = mp[a[i]];

   return res;
}

int rmq(int L, int R, int l, int r, int n, int tree_index=1){
   if(l > r || l < 0 || r > n - 1)
      return 0;

   if(r < L || l > R)
      return 0;

   if(l <= L && R <= r)
      return t[tree_index];

   int mid = (L + R) / 2;

   int t1 = rmq(L, mid, l, r, n, tree_index * 2);
   int t2 = rmq(mid + 1, R, l, r, n, tree_index * 2 + 1);

   return max(t1, t2);
}

int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   int n, q;
   cin >> n >> q;

   vector <int> a(n);
   for(int i = 0; i < n; i++)
      cin >> a[i];

   vector <int> freq_arr = get_frequency_array(a, n);

   build(freq_arr, 0, n - 1);

   while(q--){
      int l, r;
      cin >> l >> r;

      l--; r--;

      int maxOccur = 0;

      if(a[l] == a[r])
         maxOccur = r - l + 1;
      else{
         int leftmost_same = 0, rightmost_same = 0;

         while(l > 0 && l <= r && a[l] == a[l - 1]){
            leftmost_same++;
            l++;
         }

         while(r < n - 1 && l <= r && a[r] == a[r + 1]){
            rightmost_same++;
            r--;
         }

         maxOccur = max(max(leftmost_same, rightmost_same), rmq(0, n - 1, l, r, n));
      }

      cout << maxOccur << '\n';
   }

   int zero;
   cin >> zero;

   return 0;
}