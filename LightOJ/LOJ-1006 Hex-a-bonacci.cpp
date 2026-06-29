// starting : 2026-06-29 15:47:03
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define setbits(x) __builtin_popcountll(x)
#define endl '\n'
#define print(v) for(auto e:v) cout<<e<<" "; cout<<endl;

const ll N = 1e5 + 10, mod = 1e9+7;

int a,b,c,d,e,f,n;
ll dp[N];

ll fn(int x) {
    if(x == 0) return a % 10000007;
    if(x == 1) return b % 10000007;
    if(x == 2) return c % 10000007;
    if(x == 3) return d % 10000007;
    if(x == 3) return d % 10000007;
    if(x == 4) return e % 10000007;
    if(x == 5) return f % 10000007;

    ll &ans = dp[x];
    if(ans != -1) return ans;
    ans = 0;
    for(int i = 1; i <= 6; i++) {
        ans += fn(x - i);
        ans %= 10000007;
    }
    
    return ans;
}

void solve(int t) {
    cin >> a >> b >> c >> d >> e >> f >> n;
    cout << "Case "<< t << ": ";
    memset(dp , -1 ,sizeof dp);
    ll ans = fn(n);
    // cout << (ans % 10000007) << endl;
    cout << ans << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;  cin >> t;
    for(int i = 0; i < t; i++) {
        solve(i+1);
    }
    return 0;
}
// Coded by Mahmudul Hasan Sakib (@mahmudulsakib2019)
