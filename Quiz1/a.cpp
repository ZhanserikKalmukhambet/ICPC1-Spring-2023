#include <bits/stdc++.h>

using namespace std;

int main(){
   int n;
   cin >> n;

   int a[n];

   for(int i = 0; i < n; i++)
      cin >> a[i];

   int cur = 0, maxi = a[0];

   for(int i = 0; i < n; i++){
      cur += a[i];

      if(cur < 0)
         cur = 0;

      maxi = max(maxi, cur);
   }

   cout << maxi;

   return 0;
}