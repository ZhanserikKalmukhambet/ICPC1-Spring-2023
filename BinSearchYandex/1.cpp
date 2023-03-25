#include <bits/stdc++.h>

using namespace std;

bool check(int n, int k, int tar){
   return 3 * (k + tar) >= n + tar;
}

/*
      Total number of employees - n (parents, teachers, directors)
      We have one rule : number of parents should be at least 1/3 greater than the total - k >= n / 3
      Find minimum addition to k such that it follows the rule - k >= n / 3
*/

int main(){
   int n, k;
   cin >> n >> k;

   int l = 0, r = n;

   while(l <= r){
      int mid = l + (r - l) / 2;

      if(check(n, k, mid))
         l = mid + 1;
      else
         r = mid;
   }

   cout << l;

   return 0;
}