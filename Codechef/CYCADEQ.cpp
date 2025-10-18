// Problem Link :- https://www.codechef.com/problems/CYCADEQ
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
void solve() {
    int n,c; cin >> n >> c;
    vector<ll>b(n),d(n);
    for(int i = 0 ; i < n ; i++) cin >> b[i];
    for(int i = 0 ; i < n ; i++) cin >> d[i];

    vector<ll>temp = b;
    ll ans = 1e18;
    for(int k = 0; k < n; k++) { 
        ll tot = k * c;
        for(int i = 0;  i < n; i++) {
            int pos = (i - k + n) % n;
            temp[i] = min(temp[i] , b[pos]);
            tot += d[i] * temp[i];
        }
        ans = min(tot,ans);
    }
    cout << ans << endl;
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
