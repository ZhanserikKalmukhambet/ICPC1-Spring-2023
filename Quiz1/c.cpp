#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int> > factors;
void getFactors(int n) {
    factors.clear();
    int d = 1;
    for (int i = 2; i * i <= n; i += d, d = 2)
        if (n % i == 0) {
            factors.push_back(make_pair(i, 0));
            while (n % i == 0) {
                n /= i;
                factors.back().second++;
            }
        }
    if (n != 1)
        factors.push_back(make_pair(n, 1));
}
 
vector<int> divisors;
void getDivisors(int ind = 0, int res = 1) {
    if (ind == (int) factors.size()) {
        divisors.push_back(res);
        return;
    }
    for (int i = 0; i <= factors[ind].second; i++) {
        getDivisors(ind + 1, res);
        res *= factors[ind].first;
    }
}
 
vector<int> getCDs(int a, int b) {
    getFactors(a);
    divisors.clear();
    getDivisors();
    vector<int> d1 = divisors;
    getFactors(b);
    divisors.clear();
    getDivisors();
    vector<int> d2 = divisors;
    sort(d1.begin(), d1.end());
    sort(d2.begin(), d2.end());
    vector<int> cd;
    set_intersection(d1.begin(), d1.end(), d2.begin(), d2.end(), inserter(cd,
            cd.begin()));
    return cd;
}
 
int main() {
    int a, b, n;
    scanf("%d%d", &a, &b);
    vector<int> cd = getCDs(a, b);
    scanf("%d", &n);
    int low, high, ind;
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &low, &high);
        ind = -1;
        for (int j = ((int) cd.size()) - 1; j >= 0; j--)
            if (cd[j] >= low && cd[j] <= high) {
                ind = j;
                break;
            }
        if (ind == -1)
            printf("-1\n");
        else
            printf("%d\n", cd[ind]);
    }
    return 0;
}