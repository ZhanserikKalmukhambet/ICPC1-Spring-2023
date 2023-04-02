#include <bits/stdc++.h>

using namespace std;

int binPow(int x, int n){
   if(n == 0)
      return 1;

   if(n % 2 == 0){
      int temp = binPow(x, n / 2);
      return temp * temp;
   }
   else{
      return binPow(x, n - 1) * x;
   }
}

int main(){
   int a, b;
   cin >> a >> b;

   cout << binPow(a, b);
}