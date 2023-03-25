#include <bits/stdc++.h>

using namespace std;

/*
   Саша выбрал N задач чтобы подготовиться к Яндексу. Он первый день решил k задач и каждый следующий день решил на 1 больше задач.
   Найдите количество дней требуемое Саше решать N проблем. 
   
   a1 = k, d = 1, a_last = k + days - 1
   s = n * (a1 + a_last) / 2
   s = n * (2k + days - 1) / 2
*/

bool check(int n, int k, int tar){
   return // sth ;
}

int main(){
   int n, k;
   cin >> n >> k;

   int l = 0, r = n;
   while(l <= r){
      int mid = l + (r - l) / 2;

      if(check(n, k, mid))
         l = mid - 1;
      else
         r = mid;
   }

   cout << l;
   return 0;
}