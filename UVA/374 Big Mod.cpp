
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9+7;
ll Pow(long long a, long long b, ll mod) {
    long long ans = 1;
    a %= mod;
    while (b > 0) {
        if (b & 1) ans = (1LL * ans * a) % mod ;
        a = (1LL * a * a )% mod;
        b >>= 1;
    }
    return ans;
}

void solve() {
    ll a,b,c; 
    while (cin >> a >> b >> c)
    {
        ll ki = Pow(a,b,c);
        ki %= c;
        cout << ki << endl;
    }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
