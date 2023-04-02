#include <bits/stdc++.h>

using namespace std;

int findPrimesCnt(int a, int b){

   int isPrime[b+1];
   for(int i=2; i<=b; i++)
      isPrime[i] = 1;
   
   for(int i=2; i<=b; i++){
      if(isPrime[i] == 1){
         int j = i+i;
         while(j <= b){
            isPrime[j] = 0;
            j += i;
         }
      }
   }

   int cnt = 0;
   for(int i=a; i<=b; i++)
      if(isPrime[i] == 1)
         cnt++;
         
   return cnt;
}

int main(){
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);

   int a, b;
   
   while(cin >> a >> b){
      cout << findPrimesCnt(a, b) << '\n' << '\n';
   }
}