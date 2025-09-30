// Problem Link :- https://codeforces.com/contest/1742/problem/D
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
ll gcd(ll a, ll b) {
    while (b != 0) {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
void solve() {
    int n; cin >> n;
    vector<int>p(1001,-1),q,r;
    for(int i = 0 ; i < n; i++){
        ll x; cin >> x;
        p[x] = max(p[x] ,i+1);
    }
    int ans = -1;
    for(int i = 1; i <= 1000;i++){
        if(p[i] == -1) continue;
        for(int j = 1 ; j <= 1000;j++) {
            if(p[j] == -1) continue;
            ll k = gcd(i,j);
            if(k == 1){
                ans = max(ans , p[i]+p[j]);
            }
        }
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
