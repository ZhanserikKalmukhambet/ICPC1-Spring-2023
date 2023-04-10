#include <bits/stdc++.h>

using namespace std;

int main(){
   int t;
   cin >> t;

   while(t--){
      int n, d;
      string s;

      bool ok = false;

      cin >> n >> d >> s;

      for(int i = 0; i < n; i++){
         if(d > s[i] - '0' && !ok){
            cout << d;
            ok = true;
         }

         cout << s[i];
      }

      if(!ok)
         cout << d;

      cout << '\n';
   }
}