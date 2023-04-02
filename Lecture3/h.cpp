#include <bits/stdc++.h>

using namespace std;

vector <string> res;

void gen(int n, string s, int i){
   if(i >= n){
      res.push_back(s);
      return;
   }

   s[i] = '0';
   gen(n, s, i + 1);
   s[i] = '1';

   if(i == 0 || s[i - 1] != '1')
      gen(n, s, i + 1);
}

int main(){
   int n;
   cin >> n;

   string s;
   for(int i = 0; i < n; i++)
      s += " ";

   gen(n, s, 0);

   for(auto str : res)
      cout << str << '\n';
}