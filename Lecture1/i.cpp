#include <bits/stdc++.h>

using namespace std;

int binPow(int a, int n){
   if(n == 0)
      return 1;

   if(n % 2 == 1)
      return binPow(a, n-1) * a;
   else{
      int temp = binPow(a, n/2);
      return temp*temp;
   }
}

int main(){
   int a, n;
   cin >> a >> n;

   cout << binPow(a, n);
}