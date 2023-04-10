#include <bits/stdc++.h>

using namespace std;

const int N = 111;

vector<int> g[N];

bool used[N];

vector<pair<int, int>> res;

void dfs(int v){
   used[v] = 1;

   for(auto u : g[v]){
      if(!used[u]){
         res.push_back(make_pair(v, u));
         dfs(u);
      }
   }
}

int main(){
   int n, m;
   cin >> n >> m;

   for(int i = 0; i < m; i++){
      int x, y;
      cin >> x >> y;

      g[x].push_back(y);
      g[y].push_back(x);
   }

   dfs(1);

   for(auto p : res)
      cout << p.first << ' ' << p.second << '\n';

   return 0;
}