#include <bits/stdc++.h>

using namespace std;

int used[10010];
vector<int> g[10010];

void dfs(int v, vector<int>& dp){
   used[v] = 1;

   for(auto u : g[v]){
      if(!used[u])
         dfs(u, dp);
      
      dp[v] = max(dp[v], 1 + dp[u]);
   }
}

int main(){
   freopen("longpath.in", "r", stdin);
   freopen("longpath.out", "w", stdout);

   int n, m;
   cin >> n >> m;

   for(int i=0; i<m; i++){
      int a, b;
      cin >> a >> b;

      g[a].push_back(b);
   }

   vector <int> dp(n+1, 0);

   for(int i=1; i<=n; i++)
      if(!used[i])
         dfs(i, dp);

   int res = 0;
   for(auto x : dp)
      res = max(res, x);

   cout << res;
}