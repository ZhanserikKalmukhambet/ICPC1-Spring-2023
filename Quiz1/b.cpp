#include <bits/stdc++.h>

using namespace std;

#define ll unsigned long long

int main(){
   int t;
   cin >> t;

   vector <int> res;

   while(t--){
      ll n, m;
      cin >> n >> m;

      if(m >= n){
         res.push_back(1);
      }
      else{
         if(n % (m + 1) == 0)
            res.push_back(2);
         else
            res.push_back(1);
      }
   }

   for(auto i : res)
      cout << i;
  
   return 0;
}