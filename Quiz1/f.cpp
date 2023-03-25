#include <bits/stdc++.h>

using namespace std;

int main(){
   int n, a, b;
   string s;

   cin >> n >> a >> b >> s;

   s = '*' + s;
   s += '*';

   int sz = s.size();
   int l = 0;
   int cnt = 0;

   for(int r = 1; r < sz; r++){
      if(s[r] == '*'){
         int len = r - l - 1;
         l = r;

         if(len == 0)
            continue;

         if(len % 2 == 0){
            cnt += min(len / 2, a);
            a -= min(len / 2, a);

            cnt += min(len / 2, b);
            b -= min(len / 2, b);
         }
         else{
            if(a > b){
               cnt += min((len + 1) / 2, a);
               a -= min((len + 1) / 2, a);

               cnt += min(len / 2, b);
               b -= min(len / 2, b);
            }
            else{
               cnt += min((len + 1) / 2, b);
               b -= min((len + 1) / 2, b);

               cnt += min(len / 2, a);
               a -= min(len / 2, a);
            }
         }
      }
   }

   cout << cnt;

   return 0;
}