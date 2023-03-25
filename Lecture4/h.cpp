#include <bits/stdc++.h>

using namespace std;

bool cmp(pair< pair<int, int>, int > a, pair< pair<int, int>, int > b){
   int temp1 = b.first.second * a.first.first, 
       temp2 = b.first.first * a.first.second;

   if(temp1 == temp2)   
      return a.second < b.second;

   return temp1 < temp2;
}

int main(){
      int n;
      while(cin >> n){

         vector < pair< pair<int, int>, int > > v(n);
         for(int i = 0; i < n; i++){
            cin >> v[i].first.first >> v[i].first.second;
            v[i].second = i + 1;
         }

         sort(v.begin(), v.end(), cmp);

         for(auto p : v)
            cout << p.second << ' ';
         
         cout << '\n';
      }
}