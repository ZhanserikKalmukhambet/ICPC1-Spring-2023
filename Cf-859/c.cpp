#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>

int main(){
   int t;
   cin >> t;
   
   while(t--){
      int n;
      string s;

      cin >> n >> s;

      map <char, int> mp;

      bool ok = true;
      int val = 1;

      for(int i = 0; i < n; i++){
         map<char, int>::iterator it = mp.find(s[i]);

         if(it == mp.end()){
            mp[s[i]] = val;
         }
         else if(mp[s[i]] != val){
            ok = false;
            break;
         }

         // cout << s[i] << ' ' << mp[s[i]] << '\n';

         if(i % 2 == 0)
            val = 0;
         else
            val = 1;
      }

      if(ok)
         cout << "YES" << '\n';
      else
         cout << "NO" << '\n';
   }
}