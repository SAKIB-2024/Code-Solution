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

    int T;
    cin >> T;
    while (T--) {
        ll n, k;
        cin >> n >> k;
        long double x = k * log10((long double)n);
        long double frac = x - floor(x);
        int leading = (int)(pow(10.0L, frac) * 100); 

        int trailing = (int)modpow(n, k, 1000);

        cout << leading << "...";
        cout << setw(3) << setfill('0') << trailing << "\n";
    }

    return 0;
}
