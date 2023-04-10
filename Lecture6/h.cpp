#include <bits/stdc++.h>

using namespace std;

bool cycle = false;

#define ll long long
#define pb push_back
#define mp make_pair

const int N = 100;

vector<int> g[N];

bool used[N];
bool rec_stack[N];

bool dfs(int v){
   used[v] = 1;
   rec_stack[v] = 1;

   for(auto u : g[v]){
      if(!used[u] && dfs(u)){
         return true;
      }
      else if(rec_stack[u])
         return true;
   }

   rec_stack[v] = 0;
   
   return false;
}

int main(){
   int n;
   cin >> n;

   for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
         int x;
         cin >> x;

         if(x == 1)
            g[i].pb(j);
      }
   }

   for(int i = 0; i < n; i++){
      if(!used[i] && dfs(i)){
         cycle = true;
         break;
      }
   }

   if(cycle)
      cout << 1;
   else
      cout << 0;
}