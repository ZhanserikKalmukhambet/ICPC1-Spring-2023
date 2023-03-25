#include <bits/stdc++.h>

using namespace std;

int binSearch(vector<int> v, int l, int r, int tar){
   int mid, ans = -1;

   while(l <= r){
      mid = (l + r) / 2;

      if(tar < v[mid]){
         r = mid - 1;
      }
      else{
         ans = mid;
         l = mid + 1;
      }
   }
   return ans;
}

int main(){
   int n;
   cin >> n;

   int a[n];
   for(int i=0; i<n; i++)
      cin >> a[i];

   vector <int> v;
   for(int i=0; i<n; i++){
      if(v.size() == 0)
         v.push_back(a[i]);
      else {
         sort(v.begin(), v.end());

         int maxInd = binSearch(v, 0, v.size()-1, a[i]);

         if(maxInd == -1)
            v.push_back(a[i]);
         else
            v[maxInd] = a[i];
      }
   }

   cout << v.size();
}