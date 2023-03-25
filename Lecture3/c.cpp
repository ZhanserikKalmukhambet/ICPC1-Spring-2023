#include <bits/stdc++.h>

using  namespace std;

#define pii pair<int, int>
#define mp make_pair

int findMinGreater(vector<pii> temp, int tar){
   int res = INT_MAX;
   int ind = -1;
   for(auto p : temp){
      if(tar < p.first && p.first < res){
         res = p.first;
         ind = p.second;
      }
   }

   return ind;
}

void print(vector<int> a){
   for(auto val : a)
      cout << val << ' ';
}

int main(){
   freopen("success.in", "r", stdin);
   freopen("success.out", "w", stdout);

   int n;
   cin >> n;

   vector<int> a(n);
   for(int i=0; i<n; i++)
      cin >> a[i];

   vector<pii> temp;
   int st;
   bool ok = false;
   
   for(int i=n-1; i>0; i--){
      temp.push_back(mp(a[i], i));
      
      if(a[i] > a[i-1]){
         ok = true;

         st = i;

         int pos = findMinGreater(temp, a[i-1]);
         swap(a[i-1], a[pos]);

         break;
      }
   }

   if(!ok){
      reverse(a.begin(), a.end());
      print(a);
      return 0;
   }

   vector <int> tail;
   for(int i=st; i<n; i++)
      tail.push_back(a[i]);
   
   reverse(tail.begin(), tail.end());

   int ind = 0;
   for(int i=st; i<n; i++){
      a[i] = tail[ind];
      ind++;
   }

   print(a);
}