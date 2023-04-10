#include <bits/stdc++.h>

using namespace std;

const int N = 111;

vector<int> g[N];
vector<int> d(N, N);

bool used[N];

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
         }
      }
   }
}

int main(){
   int n;
   cin >> n;

   for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
         int x;
         cin >> x;

         if(x == 1){
            g[i + 1].push_back(j + 1);
            g[j + 1].push_back(i + 1);
         }
      }
   }

   int st, end;
   cin >> st >> end;

   bfs(st);

   if(!used[end])
      cout << -1;
   else
      cout << d[end];

   return 0;
}