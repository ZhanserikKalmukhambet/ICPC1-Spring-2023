#include <bits/stdc++.h>

using namespace std;

#define ll long long

// solved by - Range Minimum Query

int main(){
   // freopen("stupid_rmq.in", "r", stdin);
   // freopen("stupid_rmq.out", "w", stdout);

   int n;
   cin >> n;

   ll a[n];
   for(int i = 0; i < n; i++)
      cin >> a[i];

   int q;
   cin >> q;

   while(q--){
      int l, r;
      ll mini = INT_MAX;

      cin >> l >> r;

      l--; r--;

      int len = (int) sqrt (n + .0) + 1;

      vector <ll> b(len, INT_MAX);
      
      for(int i = 0; i < n; i++)
	      b[i / len] = min(b[i / len], a[i]);

      for(int i = l; i <= r;){

         if (i % len == 0 && i + len - 1 <= r){
            mini = min(mini, b[i / len]);
			   i += len;
		   }
         else {
            mini = min(mini, a[i]);
            i++;
         }
      }

      cout << mini << '\n';
   }
}