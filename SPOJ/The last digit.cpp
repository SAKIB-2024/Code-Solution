// Problem Link :- https://www.spoj.com/problems/LASTDIG/
#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll modpow(ll a, ll b, ll mod) {
    ll res = 1 % mod;
    a %= mod;
    while (b > 0) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin >> T;
    while (T--) {
        ll n, k;cin >> n >> k;
        int trailing = (int)modpow(n, k, 10);
        cout << trailing << endl;
    }
    return 0;
}
