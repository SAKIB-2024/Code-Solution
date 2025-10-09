#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
int n;
const int N = 1e5+10;
int p[N],dp[N];
ll fts(int i) {
    if(i == n-1) return 0;
    if(dp[i]!=-1) return dp[i];

    ll k = fts(i+1) + abs(p[i+1] - p[i]);
    ll j = 1e18;
    if(i+2 < n){
        j = fts(i+2) + abs(p[i+2] - p[i]);
    } 
    
    return dp[i] = min(k,j);
}
void solve() {
    cin >> n;
    for(int i = 0 ;i < n;i++) {
        cin >> p[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << fts(0) << endl;
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
