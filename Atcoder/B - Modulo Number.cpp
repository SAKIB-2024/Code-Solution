#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int mod = 998244353;
void solve() {
    ll n; cin >> n;
    n %= mod;
    if(n < 0) n += mod;
    cout << n << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
