#include <bits/stdc++.h>

using namespace std;

vector<int> g[1010];

int main(){
   int n, m;
   cin >> n >> m;

   for(int i = 0; i < m; i++){
      int x, y;
      cin >> x >> y;

      g[x].push_back(y);
      g[y].push_back(x);
   }

   int cnt = 0;
   for(int i = 1; i <= n; i++)
      if(g[i].size() == 1)
         cnt++;

   cout << cnt;

   return 0;
}