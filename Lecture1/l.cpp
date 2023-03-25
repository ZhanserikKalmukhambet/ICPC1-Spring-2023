#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
   ll n;

   while(cin >> n){
      int result = n;

      if(n == 0)
         break;

      for(int i=2; i*i<=n; i++){
         if(n % i == 0){
            while(n % i == 0)
               n /= i;
            result -= result/i;
         }
      }

      if(n > 1)
         result -= result/n;

      cout << result << '\n';
   }

   return 0;
}