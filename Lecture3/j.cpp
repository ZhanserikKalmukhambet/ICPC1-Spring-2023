#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> res;

void genPartition(vector<int> a, int ind, int sum, vector<int>& temp){
   if(sum == n){
      res.push_back(temp);
      return;
   }

   if(ind < 0)
      return;

   genPartition(a, ind-1, sum, temp);

   if(sum < n){
      temp.push_back(a[ind]);

      genPartition(a, ind, sum + a[ind], temp);

      temp.pop_back();
   }
}

int main(){
   cin >> n;

   vector<int> a(n);
   for(int i=0; i<n; i++)
      a[i] = i+1;
   
   vector<int> temp;
   genPartition(a, n-1, 0, temp);

   for(auto v : res){
      for(auto val : v)
         cout << val << ' ';
      cout << '\n';
   }
}