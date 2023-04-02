#include <bits/stdc++.h>

using namespace std;

#define ll unsigned long long

const int N = 1000001;
int isPrime[N];

vector <ll> almPrimes;

int binSearch(ll tar){
   int l = 0, r = almPrimes.size() - 1, mid, pos = -1;

   while(l <= r){
      mid = (l + r) / 2;

      if(almPrimes[mid] <= tar){
         pos = mid;
         l = mid + 1;
      }
      else
         r = mid - 1;
   }

   return pos;
}

void genPrimes(){

   for(int i = 2; i < N; i++)
      isPrime[i] = 1;
   
   isPrime[0] = isPrime[1] = 0;

   for(int i = 2; i * i < N; i++){
      if(isPrime[i] == 1){
         int j = i * i;

         while(j < N){
            isPrime[j] = 0;
            j += i;
         }
      }
   }

   for(int i = 2; i < N; i++){
      if(isPrime[i]){
         ll j = i * i;

         while(j < 1000000000001){
            almPrimes.push_back(j);
            j *= i;
         }
      }
   }

   almPrimes.push_back(1000000000001);
   sort(almPrimes.begin(), almPrimes.end());
}

int main(){
   genPrimes();

   // for(int i = 0; i < 10; i++)
   //    cout << almPrimes[i] << ' ';

   int t;
   cin >> t;

   while(t--){
      ll l, r;
      cin >> l >> r;

      int leftInd = binSearch(l);
      int rightInd = binSearch(r);

      cout << rightInd - leftInd << '\n';
   }
}