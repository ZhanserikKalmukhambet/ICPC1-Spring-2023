#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> res;

void permute(vector<int>& a, int ind){
   if(ind >= a.size()){
      res.push_back(a);
      return;
   }

   for(int i=ind; i<a.size(); i++){
      swap(a[ind], a[i]);

      permute(a, ind + 1);

      // reset
      swap(a[ind], a[i]);
   }
}

int main(){
   freopen("perm.in", "r", stdin);
   freopen("perm.out", "w", stdout);

   int n;
   cin >> n;

   vector<int> a;
   for(int i=0; i<n; i++){
      a.push_back(i+1);
   }
   
   permute(a, 0);

   
   sort(res.begin(), res.end());

   for(auto v : res){
      for(auto val : v)
         cout << val << ' ';
      cout << '\n';
   }
}