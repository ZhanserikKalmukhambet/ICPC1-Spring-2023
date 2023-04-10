#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>

#define pcc pair<char, char>

map<string, pii> mp;

map<char, char> rev;

int main(){
   mp["UR"] = {-1, 1};
   mp["UL"] = {-1, -1};
   mp["DR"] = {1, 1};
   mp["DL"] = {1, -1};

   rev['D'] = 'U';
   rev['U'] = 'D';
   rev['L'] = 'R';
   rev['R'] = 'L';

   int t;
   cin >> t;

   while(t--){
      int n, m, stRow, stCol, endRow, endCol;
      string s;

      cin >> n >> m >> stRow >> stCol >> endRow >> endCol >> s;

      stCol--; stRow--; endCol--; endRow--;

      bool found = false;

      int cnt = 0;

      bool used[n][m];
      for(int i = 0; i < n; i++)
         for(int j = 0; j < m; j++)
            used[i][j] = false;

      queue <pii> q;
      q.push({stRow, stCol});

      while(!q.empty()){
         pii dir = mp[s];

         pii pos = q.front();
         q.pop();

         while(pos.first >= 0 && pos.first < n && pos.second >= 0 && pos.second < m){
            if(pos.first == endRow && pos.second == endCol){
               found = true;
               break;
            }

            pos.first += dir.first;
            pos.second += dir.second;
         }

         if(found)
            break;
         else{
            if(pos.first == -1) 
               pos.first++;
            if(pos.second == -1) 
               pos.second++;
            if(pos.first == n) 
               pos.first--;
            if(pos.second == m) 
               pos.second--;
         }


         if(pos.first == 0 && pos.second == 0) break;
         if(pos.first == 0 && pos.second == m - 1) break;
         if(pos.first == n - 1 && pos.second == 0) break;
         if(pos.first == n - 1 && pos.second == m - 1) break;
         
         
         if(!used[pos.first][pos.second]){
            q.push({pos.first, pos.second});

            used[pos.first][pos.second] = true;

            if(pos.first == 0){
               s[0] = rev[s[0]];
            }
            else if(pos.first == n - 1){
               s[0] = rev[s[0]];
            }
            else if(pos.second == 0){
               s[1] = rev[s[1]];
            }
            else{
               s[1] = rev[s[1]];
            }
         }
      }

      if(found)
         cout << cnt << '\n';
      else
         cout << -1 << '\n';
   }
}