#include <bits/stdc++.h>

using namespace std;

const int N = 1e5;

vector<int> g[N];

bool used[N];

vector<int> d(N, N);
vector<int> pred(N, -1);

void bfs(int v){
   used[v] = 1;

   d[v] = 0;

   queue <int> q;
   q.push(v);

   while(!q.empty()){
      int v = q.front();
      q.pop();

      for(auto u : g[v]){
         if(!used[u]){
            q.push(u);

            used[u] = 1;

            d[u] = min(d[u], d[v] + 1);

            pred[u] = v;
         }
      }
   }
}

int main(){
   int n, m;
   cin >> n >> m;

   int st, end;
   cin >> st >> end;

   for(int i = 0; i < m; i++){
      int x, y;
      cin >> x >> y;

      g[x].push_back(y);
      g[y].push_back(x);
   }

   bfs(st);

   if(!used[end]){
      cout << -1;
      return 0;
   }

   vector <int> path;
   path.push_back(end);

   while(pred[end] != -1){
      path.push_back(pred[end]);

      end = pred[end];
   }

   reverse(path.begin(), path.end());

   cout << path.size() - 1 << '\n';

   for(auto v : path)
      cout << v << ' ';
}