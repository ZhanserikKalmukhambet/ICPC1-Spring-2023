#include <bits/stdc++.h>

using namespace std;

bool check(vector<vector<int>> res, vector<int> temp){
   for(auto v : res)
      if(v == temp)
         return false;

   return true;
}

void genPartition(vector<int> a, int n, int tar, int ind, int sum, vector<int>& temp, vector<vector<int>>& res){
   if(sum == tar){
      if(check(res, temp))
         res.push_back(temp);
      return;
   }
   if(ind >= n)
      return;

   for(int i=ind; i<n; i++){
      if(sum + a[i] <= tar){
         temp.push_back(a[i]);
         genPartition(a, n, tar, i+1, sum + a[i], temp, res);

         temp.pop_back();
      }
      else{
         genPartition(a, n, tar, i+1, sum, temp, res);
      }
   }
}

int main(){
   int tar, n;

   while(cin >> tar >> n){
      vector<int> a(n);
      for(int i=0; i<n; i++)
         cin >> a[i];

      vector<vector<int>> res;
      vector<int> temp;
      genPartition(a, n, tar, 0, 0, temp, res);

      
      cout << "Sums of " << tar << ":" << '\n';
      if(res.size() == 0){
         cout << "NONE" << '\n';
      }
      else{
         for(auto v: res){
            for(int i=0; i<v.size(); i++){
               cout << v[i];
               if(i != v.size()-1)
                  cout << '+';
            }
            cout << '\n';
         }   
      }
   }
}