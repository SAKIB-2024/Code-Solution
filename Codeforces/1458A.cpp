#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll gcd(ll a, ll b) {
    while (b != 0)
    {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
void solve() {
    int n , m; cin >> n >> m;
    vector<ll>a(n),b(m);
    
    for(int i = 0 ; i < n ; i++) cin >> a[i];
    for(int i = 0 ; i < m ; i++) cin >> b[i];
    ll trk = 0;
    for(int i = 1 ; i < n ; i++ ) {
        trk = gcd(trk , abs(a[i] - a[0]));
    }
    for(int i = 0 ; i < m ; i++) {
        cout << gcd(trk , a[0] + b[i]) << ' ';
    }
    cout << endl;
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
