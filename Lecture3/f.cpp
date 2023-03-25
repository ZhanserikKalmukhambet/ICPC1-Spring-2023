#include <bits/stdc++.h>

using namespace std;

#define ll unsigned long long

ll fac(ll x){
   ll res = 1;
   for(ll i=1; i<=x; i++)
      res *= i;
   
   return res;
}

ll comb(ll a, ll b){
   return fac(a) / (fac(b) * fac(a-b));
}

int main(){
   freopen("comb.in", "r", stdin);
   freopen("comb.out", "w", stdout);

   int n, k, p;
   cin >> n >> k >> p;

   ll total = comb(n, k);
   
   vector <int> v;
   int st = 1;
   int pos = 1;
   ll cnt;

   while(v.size() != k){
      for(int i=st; i<=n; i++){
         ll a = n - i;
         ll b = k - pos;

         cnt = comb(a, b);

         p -= cnt;

         if(p < 0){
            st = i;
            break;
         }
      }

      v.push_back(st);
      p += cnt;
      pos++;
      st++;
   }

   for(auto val : v)
      cout << val << ' ';
}