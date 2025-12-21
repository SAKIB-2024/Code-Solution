#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
#define print(v) for(auto e:v) cout<<e<<" "; cout<<endl;
const int N = 20005, mod = 998244353;
void solve() {
    int n, m ; cin >> n >> m;
    vector<int>p(n),q(m),pre(m+1 ,0);
    for(int i = 0;i < n; i++) {
        cin >> p[i];
    }
    ll ans = 0;
    for(int i = 0 ; i < m; i++) {
        cin >> q[i];
        
    }
    sort(q.begin() , q.end());
    for(int i = 0 ; i < m; i++) {
        pre[i+1] = (pre[i] + q[i]) % mod;
    }
    for(int i = 0 ; i < n; i++) {
        ll x = p[i];
        ll k = upper_bound(q.begin() , q.end() , x) - q.begin();
        ll left = ((x * k) % mod - pre[k] + mod) % mod;
        ll rigth = ((pre[m] - pre[k] + mod) % mod - ((m - k) * x) % mod + mod) % mod;
  
        ans = (ans + left + rigth) % mod;
    
    }
    cout << ans << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;// cin >> t;
    for(int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}
