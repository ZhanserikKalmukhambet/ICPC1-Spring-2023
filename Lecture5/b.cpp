#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
   int n, q;
   cin >> n >> q;

   int a[n];
   for(int i = 0; i < n; i++)
      cin >> a[i];

   int len = (int) sqrt (n + .0) + 1;

   vector <int> b(len);
         
   for(int i = 0; i < n; i++)
      b[i / len] += a[i];

   while(q--){

      char c;
      cin >> c;

      if(c == '?'){
         int l, r;
         ll sum = 0;
         cin >> l >> r;

         l--; r--;

         for(int i = l; i <= r;){

            if(i % len == 0 && i + len - 1 <= r){
               sum += b[i / len];
               i += len;
            }
            else{
               sum += a[i];
               i++;
            }
         }

         cout << sum << '\n';
      }
      else{
         int pos, val;
         cin >> pos >> val;

         pos--;

         b[pos / len] = b[pos / len] - a[pos] + val;
         
         a[pos] = val;
      }
   }
}