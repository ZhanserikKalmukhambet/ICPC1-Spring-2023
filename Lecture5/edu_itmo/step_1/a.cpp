#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int size = 1e6; 
ll t[4 * size];

void build(vector<ll> &v, ll L, ll R, ll tree_index=1) { 
    if (L > R)
        return; 

    if(L == R) { 
        t[tree_index] = v[L]; 
        return; 
    } 
    
    ll middle = (L + R) / 2; 

    build(v, L, middle, tree_index * 2); 
    build(v, middle + 1, R, tree_index * 2 + 1);

    t[tree_index] = t[tree_index * 2] + t[tree_index * 2 + 1]; 
} 

void print_tree(ll sz){
   for(ll i = 1; i < 2 * sz; i++)
      cout << t[i] << ' ';
}

ll get_sum(ll L, ll R, ll l, ll r,ll tree_index=1){
    if(L > r || R < l)
        return 0;

    if(l <= L && R <= r)
        return t[tree_index];

    ll mid = (L + R) / 2;

    ll ans = get_sum(L, mid, l, r, tree_index * 2) + get_sum(mid + 1, R, l, r, tree_index * 2 + 1);

    return ans;
}

void update(ll L, ll R, ll pos, ll new_val, ll tree_index=1){
    if(L == R){
        t[tree_index] = new_val;
        return;
    }

    ll mid = (L + R) / 2;

    if(pos <= mid)
        update(L, mid, pos, new_val, tree_index * 2);
    else
        update(mid + 1, R, pos, new_val, tree_index * 2 + 1);

    t[tree_index] = t[tree_index * 2] + t[tree_index * 2 + 1];
}

int main(){
   ll n, q;
   cin >> n >> q;

   vector <ll> v(n);
   for(ll i = 0; i < n; i++)
      cin >> v[i];

   build(v, 0, n - 1);

    while(q--){
        ll type, l, r;
        cin >> type >> l >> r;

        if(type == 1){
            update(0, n - 1, l, r);
        }
        else{
            cout << get_sum(0, n - 1, l, r - 1) << '\n';
        }
    }
}