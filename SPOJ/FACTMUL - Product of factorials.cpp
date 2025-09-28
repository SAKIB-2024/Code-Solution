#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define i128 __int128
const ll mod = 109546051211;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<ll>fact(1e7+9,1);
    for(int i = 1;i <= 1e7+8;i++) {
        fact[i] = 1LL * fact[i-1] * i % mod;
    }
    int n; cin >> n;
    ll ans = 1;
    for(int i = 1;i <= n;i++) {
        ans = (i128) ans*fact[i]% mod;
    }
    cout << ans << endl;
    return 0;
}
