#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
#define print(v) for(auto e:v) cout<<e<<" "; cout<<endl;
const int N = 2e5+7, mod = 1e9+7;
int Prefix[N];
void build() {
    for(int i = 0; i <= 8; i++) {
        Prefix[i] = 2;
    }
    Prefix[9] = 3;
    for(int i = 10; i < N; i++) {
        Prefix[i] = (Prefix[i-9] + Prefix[i - 10]) % mod;
    } 
}
void solve(int t) {
    ll n , m ; cin >> n >> m ;
    ll k = n;
    set<ll>s;
    ll ans = 0;
    while (k > 0)
    {
        ll j = k % 10;
        k /= 10;
        ll trk = 10 - j;
        if(trk > m) {
            ans++;
        }
        else {
            ans += Prefix[m - trk];
        }
        
        ans %= mod;
    }

    cout << ans << endl;
    
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    build();
    int t = 1; cin >> t;
    for(int i = 0; i < t; i++) {
        solve(i+1);
    }
    return 0;
}
