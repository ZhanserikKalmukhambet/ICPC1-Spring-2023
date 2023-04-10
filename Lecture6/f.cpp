#include <bits/stdc++.h>

using namespace std;

const int N = 111;

vector<int> g[N];
bool used[N];

void dfs(int v){
   used[v] = 1;

   for(auto u : g[v]){
      if(!used[u])
         dfs(u);
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

   bool ok = true;
   for(int i = 1; i <= n; i++)
      if(!used[i]){
         ok = false;
         break;
      }
   
   if(ok)
      cout << "YES";
   else
      cout << "NO";

   return 0;
}