#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
#define print(v) for(auto e:v) cout<<e<<" "; cout<<endl;
const int N = 2e5+7, mod = 1e9+7;

struct st
{
    int idx, a, b;
};

bool ok(int mid, vector<st> &p) {
    ll k = 0;
    ll n = p.size();
    for(int i = 0 ; i < n; i++) {
        ll a = p[i].a;
        ll b = p[i].b;
        if(mid - 1 - a <= k && k <= b) k++;
    }

    return k >= mid;
}
void solve(int t) {
    int n; cin >> n;
    vector<st> p(n);

    for(int i = 0 ; i < n; i++) {
        ll a,b; cin >> a >> b;
        p[i].a = a;
        p[i].b = b;
        p[i].idx = i+1;
    }

    ll l = 0, h = n , ans = -1;

    while (l <= h)
    {
        ll mid = (l + h) >> 1;
        if(ok(mid,p)) {
            ans = mid;
            l = mid + 1;
        }
        else {
            h = mid - 1;
        }
    }
    cout << ans << endl;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; cin >> t;
    for(int i = 0; i < t; i++) {
        solve(i+1);
    }
    return 0;
}
