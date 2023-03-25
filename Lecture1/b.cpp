#include <bits/stdc++.h>

using namespace std;

void solve(){
   int n;
   cin >> n;

   bool ok = false;

   for(int i=2; i<=sqrt(2*n); i++){
      if((2*n) % i == 0){
         int a1 = (2*n) / i + 1 - i;
         if(a1 % 2 == 0){
            a1 /= 2;
            ok = true;

            cout << n << " = ";
            
            int cnt = i;
            while(cnt--){
               cout << a1++;
               if(cnt != 0)
                  cout << " + ";
            }
            cout << '\n';
            break;
         }
      }
   }

   if(!ok)  
      cout << "IMPOSSIBLE" << '\n';
}

int main(){
   int t;
   cin >> t;

   while(t--){
      solve();
   }

   return 0;
}