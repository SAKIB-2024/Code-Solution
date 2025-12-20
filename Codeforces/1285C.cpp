#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
#define print(v) for(auto e:v) cout<<e<<" "; cout<<endl;
const int N = 2e5+7, mod = 1e9+7;

ll gcd(ll a, ll b) {
    while (b != 0)
    {
        ll temp = b;
        b = a % b;
        a = temp; 
    }
    return a;
}
void solve(int t) {
    ll x; cin >> x;
    if(x == 1) {
        cout << 1 << ' ' << 1 << endl;
        return;
    }
    ll mx = 1e18;
    pair<ll,ll>ans;
    ll m = sqrtl(x);

    for(ll i = 1 ; i <= m; i++) {
        ll tt = x / i;
        ll g = gcd(tt , i);
        ll moat = (tt * i) / g;
        if(x % i == 0 && tt != i && moat == x) {
            ll mn = max(i , tt);
            

            if(mn < mx) {
                mx = mn ;
                ans = {i ,x/i};
            }
        }
    }
    cout << ans.first <<' ' << ans.second << endl;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;// cin >> t;
    for(int i = 0; i < t; i++) {
        solve(i+1);
    }
    return 0;
}
