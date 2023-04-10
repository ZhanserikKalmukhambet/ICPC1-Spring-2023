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

void update(int L, int R, int pos, int tree_index=1){
    if(L == R){
        t[tree_index] = 1 - t[tree_index];
        return;
    }

    int mid = (L + R) / 2;

    if(pos <= mid)
        update(L, mid, pos, tree_index * 2);
    else
        update(mid + 1, R, pos, tree_index * 2 + 1);

    t[tree_index] = t[tree_index * 2] + t[tree_index * 2 + 1];
}

int find(int L, int R, int k, int tree_index=1){
   if(L == R)
      return L;

   int mid = (L + R) / 2;

   if(k < t[tree_index * 2])
      return find(L, mid, k, tree_index * 2);
   else
      return find(mid + 1, R, k - t[tree_index * 2], tree_index * 2 + 1);
}

int main(){
   int n, q;
   cin >> n >> q;

   vector <int> v(n);
   for(int i = 0; i < n; i++)
      cin >> v[i];

   build(v, 0, n - 1);

    while(q--){
        int type, pos;
        cin >> type >> pos;

        if(type == 1){
            update(0, n - 1, pos);
        }
        else{
            cout << find(0, n - 1, pos) << '\n';
        }
    }
}