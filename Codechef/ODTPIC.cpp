// LINK : https://www.codechef.com/problems/ODTPIC
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
#define print(v) for(auto e:v) cout<<e<<" "; cout<<endl;

const int N = 100005, Mx = 4005;
bitset<Mx>pre_p[N],pre_q[N];

void solve() {
    int n, m, q; cin >> n >> m >> q;
    vector<int>p(n),r(m);
    pre_p[0].reset();
    for(int i = 0; i < n; i++) {
        cin >> p[i];
    }
    for(int i = 1; i <= n; i++) {
        pre_p[i] = pre_p[i-1];
        pre_p[i].flip(p[i-1]);
    }
    for(int i = 0; i < m; i++) {
        cin >> r[i];
    }
    pre_q[0].reset();
    for(int i= 1 ; i <= m; i++) {
        pre_q[i] = pre_q[i-1];
        pre_q[i].flip(r[i-1]);
    }

    while (q--)
    {
        ll l1,r1,l2,r2; cin >> l1 >> r1 >> l2 >> r2;
        auto k = pre_p[r1] ^ pre_p[l1 - 1];
        auto j = pre_q[r2] ^ pre_q[l2 - 1];
        auto z = k ^ j;
        int ans = z.count();
        cout << ans << endl;
    }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; //cin >> t;
    for(int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}
