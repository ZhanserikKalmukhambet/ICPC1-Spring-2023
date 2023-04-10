#include <bits/stdc++.h>

using namespace std;

const int N = 111;

vector<int> g[N];

int color[N];

bool ok = true;

void dfs(int v, int c){
   color[v] = c;

   for(auto u : g[v]){
      if(color[u] == -1)
         dfs(u, 3 - c);
      else if(color[u] == color[v]){
         ok = false;
         return;
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

   for(int i = 1; i <= n; i++)
      color[i] = -1;

   for(int i = 1; i <= n; i++)
      if(color[i] == -1)
         dfs(i, 1);

   if(ok)
      cout << "YES";
   else
      cout << "NO";

   return 0;
}