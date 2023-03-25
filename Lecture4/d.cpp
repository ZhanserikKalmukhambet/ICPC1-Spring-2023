#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
   priority_queue<ll,vector<ll>,greater<ll>> heap;

   ll n;
   cin >> n;

   for(ll i=0; i<n; i++){
      ll x;
      cin >> x;
      heap.push(x);
   }

   ll sum = 0;
   while(heap.size() != 1){
      ll a = heap.top();
      heap.pop();
      ll b = heap.top();
      heap.pop();

      heap.push(a + b);
      sum = sum + a + b;

   }

   cout << sum;
}