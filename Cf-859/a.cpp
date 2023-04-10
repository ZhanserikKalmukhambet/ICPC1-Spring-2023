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
      int a, b, c;
      cin >> a >> b >> c;

      if(a + b == c)
         cout << '+' << '\n';
      else
         cout << '-' << '\n';
   }
}