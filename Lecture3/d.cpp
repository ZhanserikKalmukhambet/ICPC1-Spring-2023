#include <bits/stdc++.h>

using namespace std;

vector <vector<int>> res;

void combination(int n, int k, int ind, vector<int>& temp){
   if(temp.size() == k){
      res.push_back(temp);
      return;
   }

   for(int i=ind; i<=n; i++){
      temp.push_back(i);

      combination(n, k, i+1, temp);

      temp.pop_back();
   }
}

int main(){
   freopen("choose.in", "r", stdin);
   freopen("choose.out", "w", stdout);

   int n, k;
   cin >> n >> k;

   vector<int> v;
   combination(n, k, 1, v);

   for(auto a : res){
      for(auto val : a)
         cout << val << ' ';
      cout << '\n';
   }
}