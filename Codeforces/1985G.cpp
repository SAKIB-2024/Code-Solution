#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int mod = 1e9+7;

long long Pow(ll a,ll b){
    ll ans = 1;
    while(b>0){
        if(b&1) ans=(ans*a)%mod;
        b>>=1;
        a=(a*a)%mod;
    }
    return ans;
}
void solve() {
    int l, r, k ; cin >> l >> r >> k;
    ll a = Pow((9 / k) + 1 , r);
    ll b = Pow((9 / k) + 1 , l);
    cout << (a - b + mod ) % mod << endl;
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
