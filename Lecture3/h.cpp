#include <bits/stdc++.h>

using namespace std;

void gen(string s, int i, vector<string>& v){
   if(i == s.size()){
      v.push_back(s);
      return;
   }

   s[i] = '0';
   gen(s, i+1, v);
   s[i] = '1';

   if(i == 0 || s[i-1] != '1')
      gen(s, i+1, v);
}

int main(){
   int n;
   cin >> n;

   string s;
   for(int i=0; i<n; i++)
      s += " ";
   
   vector<string> v;
   gen(s, 0, v);

   for(auto str : v){
      for(int i=0; i<str.size(); i++)
         cout << str[i] << ' ';
      cout << '\n';
   }

   return 0;
}