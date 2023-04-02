#include <bits/stdc++.h>

using namespace std;

int main(){
   int n;
   cin >> n;

   int fac = 1;

   int a[n];
   for(int i = 0; i < n; i++){
      cin >> a[i];

      fac *= i + 1;
   }
   fac /= n;

   int inv[n - 1];
   for(int i = 0; i < n - 1; i++){
      int cnt = 0;

      for(int j = i + 1; j < n; j++)
         if(a[i] > a[j])
            cnt++;
      
      inv[i] = cnt;
   }

   int order = 0;
   int temp = n - 1;
   for(int i = 0; i < n - 1; i++){
      order += inv[i] * fac;

      fac /= temp;
      temp--;
   }

   cout << order + 1;
   return 0;
}