#include <bits/stdc++.h>

using namespace std;

const int size = 1e6; 
int t[4 * size];

void build(vector<int> &v, int L, int R, int tree_index=1) { 
    if (L > R)
        return; 

    if(L == R) { 
        t[tree_index] = v[L]; 
        return; 
    } 
    
    int middle = (L + R) / 2; 

    build(v, L, middle, tree_index * 2); 
    build(v, middle + 1, R, tree_index * 2 + 1);

    t[tree_index] = t[tree_index * 2] + t[tree_index * 2 + 1]; 
} 

void print_tree(int sz){
   for(int i = 1; i < 2 * sz; i++)
      cout << t[i] << ' ';
}

int get_sum(int L, int R, int l, int r,int tree_index=1){
    if(L > r || R < l)
        return 0;

    if(l <= L && R <= r)
        return t[tree_index];

    int mid = (L + R) / 2;

    int ans = get_sum(L, mid, l, r, tree_index * 2) + get_sum(mid + 1, R, l, r, tree_index * 2 + 1);

    return ans;
}

int main(){
   int n;
   cin >> n;

   vector <int> v(n);
   for(int i = 0; i < n; i++)
      cin >> v[i];

   build(v, 0, n - 1);

    int l, r;
    cin >> l >> r;
    cout << get_sum(0, n - 1, l - 1, r - 1);
}