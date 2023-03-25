#include <bits/stdc++.h>

using namespace std;

int main(){
   int a, b;
   cin >> a >> b;

   int isComposite[b+1];
   for(int i=0; i<=b; i++)
      isComposite[i] = 0;

   isComposite[0] = isComposite[1] = 1;

   for(int i=2; i<b; i++){
      if(isComposite[i] == 0){
         int j = 2*i;
         while(j <= b){
            isComposite[j] = 1;
            j += i;
         }
      }
   }

   vector <int> v;
   for(int i=a; i<=b; i++)
      if(isComposite[i] == 0)
         v.push_back(i);
   
   for(int i=0; i<v.size(); i++){
      cout << v[i];
      if(i != v.size()-1)
         cout << ' ';
   }
   return 0;
}