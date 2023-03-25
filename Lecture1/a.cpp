#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

int main(){
   ll n;
   cin >> n;

   if(n == 0 || n == 1){
      cout << n;
      return 0;
   }

   vector <pair<ll, int>> ans;
   
   for(int i=2; i<=sqrt(n); i++){
      if(n % i == 0){
         int deg = 0;
         while(n % i == 0){
            n /= i;
            deg++;
         }
         ans.pb(mp(i, deg));
      }
   }

   if(n > 1)
      ans.pb(mp(n, 1));

   for(int i=0; i<ans.size(); i++){
      pair <long long, int> p = ans[i];

      cout << p.first;
      if(p.second != 1)
         cout << '^' << p.second;
      
      if(i != ans.size()-1)
         cout << '*';
   }
}