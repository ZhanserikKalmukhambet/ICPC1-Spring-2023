#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

vector <int> a(N);

int n, l;

int get_h_index(){
   int ind = n;

   while(ind > 0 && a[ind-1] < ind)
      ind--;

   return ind;
}

int main(){
   cin >> n >> l;

   for(int i = 0; i < n; i++)
      cin >> a[i];

   sort(begin(a), end(a), greater<int>());

   int h_ind = get_h_index();

   if(h_ind < n){
      for(int i = h_ind; i >= max(0, h_ind - l + 1); i--)
         a[i]++;
   }

   sort(begin(a), end(a), greater<int>());

   cout << get_h_index();

   return 0;
}