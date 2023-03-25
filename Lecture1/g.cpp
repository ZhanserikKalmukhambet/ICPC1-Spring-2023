#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int N = 1e6 + 1;
vector<ll> primes;

int binSearch(int l, int r, int tar){
   int mid;

   while(l < r){
      mid = (l + r) / 2;

      if(primes[mid] < tar)
         l = mid + 1;
      else if(primes[mid] > tar)
         r = mid - 1;
   }
   
}

void generatePrimes(){
   bool isComposite[N];
   isComposite[0] = isComposite[1] = 1;

   for(ll i=2; i<N; i++){
      if(!isComposite[i]){
         for(ll j=i*i; j<N; j+=i)
            isComposite[j] = 1;
      }
   }

   for(ll i=2; i<N; i++){
      if(!isComposite[i]){
         for(int j=i*i; j<1000000000000L; j++)
            primes.push_back(j);
      }
   }
   primes.push_back(1000000000000L);

   sort(primes.begin(), primes.end());
}

void solve(){
   generatePrimes();

   ll low, high;
   cin >> low >> high;


}

int main(){
   int t;
   cin >> t;

   while(t--){
      solve();
   }
}