#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
    int n; cin >> n;
    vector<ll>p(n),q(n);
    map<ll,ll>mpp,Mp;
    bool ok = false;
    ll even = 0;
    for(int i = 0 ; i < n ; i++) {
        cin >> p[i];
        if((p[i] & 1) == 0) {
            even++;
        }
        mpp[p[i]]++;
        if(mpp[p[i]] >= 2 && p[i] > 1) {
            ok = true;
        }
    }
    for(int i = 0 ; i < n ; i++) {
        cin >> q[i];
    }
    
    if(ok || even > 1) {
        cout << 0 << endl;
    }
    else if(even == 1) {
        ll ans = 1;
        for(int i = 0;i < n; i++) {
            ll k = p[i];
            ll m = sqrt(k);
            for(int j = 2; j <= m; j++) {
                if(k % j == 0) {
                    ll nts = k / j;
                    if(mpp[j]>0 || mpp[nts]>0) {
                        cout << 0 << endl;return;
                    }
                    mpp[j]++;
                    mpp[nts]++;
                }
            }
        }
        cout << ans << endl;
    }
    else {
        ll ans = 2;
        //sort(p.begin(),p.end());
        for(int i = 0;i < n; i++) {
            ll k = p[i];
            ll m = sqrt(k);
            for(int j = 2; j <= m; j++) {
                if(k % j == 0) {
                    ll nts = k / j;
                    if(Mp[j] > 0 || Mp[nts] > 0 || mpp[j] > 0 || mpp[nts] > 0) {
                        cout << 0 << endl;return;
                    }
                    Mp[j]++;
                    Mp[nts]++;
                }
            }
        }
        for(int i = 0; i < n; i++) {
            ll k = p[i]+1;
            ll m = sqrt(k);
            for(int j = 2; j <= m; j++) {
                if(k % j == 0) {
                    ll nts = k / j;
                    if(Mp[j] > 0 || Mp[nts] > 0 || mpp[j] > 0 || mpp[nts]>0) {
                        ans = 1;
                        cout << ans << endl;return;
                    }
                }
            }
        }
        cout << ans << endl;
    }
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
