#include <bits/stdc++.h>

using namespace std;

int main(){
   freopen("inverse.in", "r", stdin);
   freopen("inverse.out", "w", stdout);

   int n;
   cin >> n;

   int a[n];
   for(int i=0; i<n; i++)
      cin >> a[i];
   
   int res[n];
   for(int i=0; i<n; i++)
      res[a[i]-1] = i+1;
   
   for(int i=0; i<n; i++)
      cout << res[i] << ' ';

   return 0;
}