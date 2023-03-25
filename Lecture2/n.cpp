#include <bits/stdc++.h>

using namespace std;

int main(){
   int n, m;

   cin >> n;
   int a[n];

   for(int i=0; i<n; i++)
      cin >> a[i];

   cin >> m;
   int b[m];
   for(int j=0; j<m; j++)
      cin >> b[j];
   
   int lcm[n+1][m+1];
   for(int i=0; i<=n; i++)
      lcm[i][0] = 0;
   for(int j=0; j<=m; j++)
      lcm[0][j] = 0;
   
   for(int i=1; i<=n; i++){
      for(int j=1; j<=m; j++){
         if(a[i-1] == b[j-1])
            lcm[i][j] = 1 + lcm[i-1][j-1];
         else
            lcm[i][j] = max(lcm[i-1][j], lcm[i][j-1]);
      }
   }

   // for(int i=0; i<=n; i++){
   //    for(int j=0; j<=m; j++)
   //       cout << lcm[i][j] << ' ';
   //    cout << '\n';
   // }

   cout << lcm[n][m];

}