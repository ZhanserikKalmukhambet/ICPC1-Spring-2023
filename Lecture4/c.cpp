#include <bits/stdc++.h>

using namespace std;

int binSearch(int * a, int l, int r, int tar){
   int mid, ans = -1;
   while(l <= r){
      mid = l + (r - l) / 2;

      if(a[mid] <= tar){
         ans = mid;
         l = mid + 1;
      }
      else{
         r = mid - 1;
      }
   }

   return ans;
}

int main(){
   int n, k, h_index = 0;
   cin >> n >> k;

   int a[n];
   for(int i = 0; i < n; i++)
      cin >> a[i];
      
   sort(a, a + n);

   for(int l=0; l < n; l++){
      if(n - l <= a[l]){
         h_index = n - l;
         break;
      }
   }

   while(k > 0){
      int rightMostIndex = binSearch(a, 0, n - 1, h_index);

      if(rightMostIndex == -1)
         break;

      while(k > 0 && a[rightMostIndex] != h_index + 1){
         a[rightMostIndex]++;
         k--;
      }

      if(a[rightMostIndex] == h_index + 1 && a[rightMostIndex] <= n - rightMostIndex)
         h_index++;
   }

   cout << h_index;
   return 0;
}