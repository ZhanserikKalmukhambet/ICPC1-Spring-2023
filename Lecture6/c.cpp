#include <bits/stdc++.h>

using namespace std;

int main(){
   int n;
   cin >> n;

   vector<int> g[n + 1];

   for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
         int x;
         cin >> x;

         if(x == 1)
            g[i + 1].push_back(j + 1);
      }
   }

   for(int i = 1; i <= n; i++){
      cout << g[i].size() << ' ';
      for(auto val : g[i])
         cout << val << ' ';

      cout << '\n';
   }
}