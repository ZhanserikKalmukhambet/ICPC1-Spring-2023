#include <bits/stdc++.h>

using namespace std;

int main(){
   int n;
   string s1, s2;
   cin >> n >> s1 >> s2;

   int cnt = 0;
   int res = 0;
   for(int i=0; i<n; i++){
      if(s1[i] == s2[i]){
         if(cnt > 0)
            res++;
         cnt = 0;
      }
      else{
         cnt++;
      }
   }

   cout << res;
   return 0;
}