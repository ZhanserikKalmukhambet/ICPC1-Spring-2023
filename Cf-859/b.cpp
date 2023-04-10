#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>

int main(){
   int t;
   cin >> t;

   while(t--){
      int n;
      cin >> n;

      int a = 0, b = 0;

      for(int i = 0; i < n; i++){
         int x;
         cin >> x;

         if(x % 2 == 0)
            a += x;
         else
            b += x;
      }

      if(a > b)
         cout << "YES" << '\n';
      else
         cout << "NO" << '\n';
   }
}