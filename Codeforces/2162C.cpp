#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
    int a,b;cin >> a >> b;
    ll k = a ^ b;
    ll x1, x2;
    for (int i = 0; i < 31; i++) {
        ll x1 = 1LL << i;
        if (x1 <= a) {
            ll a1 = a ^ x1;
            ll x2 = a1 ^ b;
            if (x2 <= a1) {
                cout << 2 << endl;
                cout << x1 << ' ' << x2 << endl;return;
            }
        }
    }
    if(k == 0) {
        cout << 0 << endl;
    }
    else if(k <= a) {
        cout << 1 << endl;
        cout << k << endl;
    }
    else{
        bool ok = false;
        ll mn = min(a,100);
        for(int i = 0; i <= mn; i++) {
            int a1 = a ^ i;
            int y = a1 ^ b;
            if (y <= a1) {
                ok = true;
                x1 = i;
                x2 = y;
                cout << 2 << endl;
                cout << x1 << ' ' << x2 << endl;return;
            }
        }
        cout << -1 << endl;
        
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
