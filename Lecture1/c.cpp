#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
   ll n;
   cin >> n;

   int cnt = 0;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0){
            if (n / i == i)
                cnt++;
            else
                cnt = cnt + 2;
        }
    }

   cout << cnt;
   return 0;
}