#include <bits/stdc++.h>

using namespace  std;

vector<vector<char>> v;

void genBracketSeq(int n, vector<char> s, int open, int closed){
   if(s.size() == 2*n){
      v.push_back(s);
      return;
   }

   if(open < n){
      s.push_back('(');
      genBracketSeq(n, s, open+1, closed);
      s.pop_back();
   }
   
   if(closed < open){
      s.push_back(')');
      genBracketSeq(n, s, open, closed+1);
      s.pop_back();
   }
}

int main(){
   int n;
   cin >> n;

   vector <char> s;
   genBracketSeq(n, s, 0, 0);

   for(auto seq : v){
      for(auto c : seq)
         cout << c;
      cout << '\n';
   }
}