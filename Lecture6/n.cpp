#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair

const int N = 1e5 + 10;

vector<int> g[N];

bool used[N];
bool rec_stack[N];

stack <int> st;

bool top_sort(int v){
   used[v] = 1;
   rec_stack[v] = 1;

   for(auto u : g[v]){
      if(!used[u] && top_sort(u))
         return true;
      if(rec_stack[u])
         return true;
   }

   st.push(v);

   rec_stack[v] = 0;
   return false;
}

int main(){
   int n, m;
   cin >> n >> m;

   for(int i = 0; i < m; i++){
      int x, y;
      cin >> x >> y;

      g[x].pb(y);
   }

   for(int i = 1; i <= n; i++)
      if(!used[i]){
         bool cycle = top_sort(i);
         
         if(cycle){
            cout << -1;
            return 0;
         }
      }

   while(!st.empty()){
      cout << st.top() << ' ';
      st.pop();
   }

   return 0;
}