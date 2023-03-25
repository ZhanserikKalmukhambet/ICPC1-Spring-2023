#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll total;

ll fac(ll x){
   ll res = 1;
   for(ll i = 2; i <= x; i++)
      res *= i;
   
   return res;
}

ll getTotalComb(ll n){
   ll f = fac(n);
   ll cnt = 0;

   for(ll k = 0; k <= n; k++)
      cnt += f / (fac(k) * fac(n - k));

   return cnt;
}

void getComb(ll * a, ll n, ll k, ll ind, vector<ll>& temp, unordered_map<ll, ll> b){
   if(temp.size() == k){

      if(b[temp[temp.size() - 1]])
         total--;

      return;
   }
   
   for(ll i = ind; i < n; i++){
      if(temp.size() == 0)
         temp.push_back(a[i]);
      else
         temp.push_back((temp[temp.size() - 1] ^ a[i]));

      getComb(a, n, k, i + 1, temp, b);

      temp.pop_back();
   }
}

void solve(int ind){
   ll n, m;
   cin >> n >> m;

   ll a[n];
   unordered_map<ll, ll> b;

   for(ll i = 0; i < n; i++)
      cin >> a[i];
   for(ll j = 0; j < m; j++){
      ll x;
      cin >> x;

      b[x]++;
   }

   total = getTotalComb(n);   
   if(b[0]) 
      total--;
   
   for(ll k = 1; k <= n; k++){
      vector <ll> temp;

      getComb(a, n, k, 0, temp, b);
   }

   cout << "Case " << ind << ": " <<  (total % 100000007) << '\n';  
}

int main(){
   ll t;
   cin >> t;

   int ind = 1;

   while(t--){
      solve(ind);

      ind++;
   }
}              