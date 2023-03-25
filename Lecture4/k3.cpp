#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int N = 2 * 1e5;

ll n, m;

ll a[N];

bool check(ll tar){
   ll sum = 0, cnt = 0;

   for(ll i = 0; i < n; i++){
      if(a[i] >= tar){
         cnt++;
      }
      else{
         sum += a[i];

         if(sum >= tar){
            sum -= tar;

            cnt++;
         }
      }
   }

   return cnt >= m;
}

int main(){
   // freopen("justforfood.in", "r", stdin);
   // freopen("justforfood.out", "w", stdout);

   cin >> n >> m;

   for(ll i = 0; i < n; i++)
      cin >> a[i];

   sort(a, a + n);
   reverse(a, a + n);

   ll l = 0, r = 1000000000000001, mid;
   while(l <= r){
      mid = l + (r - l) / 2;

      if(check(mid)){
         l = mid + 1;
      }
      else{
         r = mid - 1;
      }
   }

   cout << r;

   return 0;
}


