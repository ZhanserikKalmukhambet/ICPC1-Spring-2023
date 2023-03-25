#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
   ll n;
   cin >> n;

   string s = "";

   while(n != 0){
      if(n % 2 == 1)
         s += "X";

      s += "S";
      n /= 2;
   }

   for(int i=s.size()-3; i>=0; i--)
      cout << s[i];

   return 0;
}