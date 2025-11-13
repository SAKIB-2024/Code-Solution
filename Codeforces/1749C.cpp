#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'

void solve() {
    int n; cin >> n;
    vector<int>p(n),q;
    set<int>s;
    for(int i =0; i < n; i++) {
        cin >> p[i];
    }
    sort(p.rbegin() , p.rend());
    ll ans = 0;
    for(int k = 0; k <= n; k++) {
        ll mid = k;
        q = p;
        ll cnt = 0;
        ll j = 0;
        ll last = n-1;
        for(int i = 1; i <= mid; i++) {
            ll gg = mid - i + 1;
            bool ok = false;
            for(;j < n; j++) {
                if(q[j] <= gg) {
                    ok = true;
                    q[last] += gg;
                    last--;
                    j++;
                    break;
                }
            }
            if(ok) {
                cnt++;
            }
        }
        if(cnt == mid) {
            ans = mid;
        }

    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; cin >> t;
    for(int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}
