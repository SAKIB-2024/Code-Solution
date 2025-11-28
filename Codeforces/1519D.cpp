// LINK :- https://codeforces.com/contest/1519/problem/D
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
#define print(v) for(auto e:v) cout<<e<<" "; cout<<endl;
const int N = 20005;

void solve() {
    int n; cin >> n;
    vector<ll>p(n),q(n),pre(n+1,0);
    pre[0] = 0;
    ll ans = 0;

    for(int i = 0; i < n ; i++) cin >> p[i];
    for(int i = 0; i < n ; i++){
        cin >> q[i];
        ans += p[i] * q[i];
        pre[i+1] = ans;
    } 

    for(int i = 0; i  < n; i++) {
        ll cur = p[i] * q[i];
        for(int l = i-1 , r = i+1; l >= 0 && r < n; l--,r++ ) {
            cur += p[l] * q[r];
            cur += p[r] * q[l];

            ans = max(ans,  cur + pre[l] + (pre[n] - pre[r+1]));
        }
        cur = 0;
        for(int l = i-1, r = i; l >= 0 && r < n; l--,r++ ) {
            cur += p[l] * q[r];
            cur += p[r] * q[l];

            ans = max(ans,  cur + pre[l] + (pre[n] - pre[r+1]));
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; // cin >> t;
    for(int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}
