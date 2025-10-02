// Problem Link :- https://www.codechef.com/problems/MINST
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
    ll n,d;cin >> n >> d;
    ll best = -1;
    for(int i = 0; i <= 60 ; i++) {
        ll pow2 = 1LL << i;
        if(pow2 > n) break;

        ll t_val = n - pow2;
        if(t_val % d !=0) continue;
        t_val /= d;
        ll k = ( t_val >> i) + __builtin_popcountll(t_val & (pow2 - 1));
        ll step = i + k;
        if(best == -1 || step < best) best = step;
    }
    cout << best << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
