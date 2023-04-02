#include <bits/stdc++.h>

using namespace std;

int binSearch(vector<int>& v, int l, int r, int tar){
   while(r - l > 1){
      int mid = l + (r - l) / 2;

      if(v[mid] < tar)
         l = mid;
      else
         r = mid;
   }
   return r;
}

int main(){
   int n;

   while(cin >> n){
      if(n == 0){
         cout << 0 << '\n';
         continue;
      }

      int a[n];
      for(int i=0; i<n; i++)
         cin >> a[i];

      vector <int> tail(n, 0);

      tail[0] = a[0];
      int length = 1;

      for(int i = 1; i < n; i++){
         if(tail[0] > a[i])
            tail[0] = a[i];

         else if(tail[length - 1] < a[i])
            tail[length++] = a[i];

         else{
            int pos = binSearch(tail, -1, length - 1, a[i]);
            tail[pos] = a[i];
         }
      }

      cout << length << '\n';
   }
}