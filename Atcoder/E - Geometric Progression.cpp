#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll Pow(ll a, ll b, ll mod) {
    ll ans = 1;
    a %= mod;
    while (b > 0) {
        if (b & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}

ll geomSum(ll x, ll a, ll mod) {
    if (x == 0) return 0;
    if (x % 2 == 0) {
        ll half = geomSum(x/2, a, mod);
        ll powHalf = Pow(a, x/2, mod);
        return (half * (1 + powHalf) % mod) % mod;
    } else {
        return (geomSum(x-1, a, mod) + Pow(a, x-1, mod)) % mod;
    }
}

void solve() {
    ll a, x, m;
    cin >> a >> x >> m;
    cout << geomSum(x, a, m) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
