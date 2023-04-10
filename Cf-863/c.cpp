#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
   int t;
   cin >> t;

   while(t--){
      int n;
      cin >> n;

      ll b[n - 1];
      
      ll a[n];

      for(int i = 0; i < n - 1; i++)
         cin >> b[i];

      for(int i = 1; i < n - 1; i++)
         a[i] = min(b[i - 1], b[i]);

      a[0] = b[0];
      a[n - 1] = b[n - 2]; 

      for(int i = 0; i < n; i++)
         cout << a[i] << ' ';

      cout << '\n';
   }
}