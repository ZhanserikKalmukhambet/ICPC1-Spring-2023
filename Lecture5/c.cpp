#include <bits/stdc++.h>

using namespace std;

int main(){
   // freopen("rvq.in", "r", stdin);
   // freopen("rvq.out", "w", stdout);

   int n = 100100;

   int a[n];

   for(int i = 0; i < n; i++)
      a[i] = ((i + 1) * (i + 1)) % 12345 + ((i + 1) * (i + 1) * (i + 1)) % 23456;

   // for(int i = 0; i < 100; i++)
   //    cout << a[i] << ' ';

   int len = (int) sqrt (n + .0) + 1;

   vector <int> b_max(len, INT_MIN);
   vector <int> b_min(len, INT_MAX);
         
   for(int i = 0; i < n; i++)
      b_max[i / len] = max(b_max[i / len], a[i]);
   
   for(int i = 0; i < n; i++)
      b_min[i / len] = min(b_min[i / len], a[i]);

   int q;
   cin >> q;
   
   while(q--){
      int l, r;
      cin >> l >> r;
      
      if(l < 0){
         l = abs(l);
         l--;

         b_max[l / len] = max(b_max[l / len], r);
         b_min[l / len] = min(b_min[l / len], r);

         a[l] = r;
      }
      else{
         l--; r--;

         int mini = INT_MAX, maxi = INT_MIN;

         for(int i = l; i <= r;){

            if(i % len == 0 && i + len - 1 <= r){
               mini = min(mini, b_min[i / len]);
               maxi = max(maxi, b_max[i / len]);

               i += len;
            }
            else{
               mini = min(mini, a[i]);
               maxi = max(maxi, a[i]);

               i++;
            }
         }

         cout << abs(maxi - mini) << '\n';
      }
   }
}