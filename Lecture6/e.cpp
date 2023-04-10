#include <bits/stdc++.h>

using namespace std;

const int N = 1000;

vector<int> g[N];

bool used[N];

int main(){
   int n;
   cin >> n;

   for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
         int x;
         cin >> x;

         if(x == 1){
            g[i + 1].push_back(j + 1);
            used[j + 1] = true;
         }
      }
   }

   vector <int> v1, v2;

   for(int i = 1; i <= n; i++)
      if(!used[i])
         v1.push_back(i);

   for(int i = 1; i <= n; i++)
      if(g[i].size() == 0)
         v2.push_back(i);

   cout << v1.size() << ' ';
   for(int x : v1)
      cout << x << ' ';
   
   cout << '\n';

   cout << v2.size() << ' ';
   for(int x : v2)
      cout << x << ' ';
}