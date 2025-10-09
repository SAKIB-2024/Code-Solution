#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
int n,k;
const int N = 1e5+10;
int p[N],dp[N];
ll fts(int i) {
    if(i == n-1) return 0;
    if(dp[i]!=-1) return dp[i];
    ll cost = 1e18;
    for(int j = i+1; j < n && j-i <= k;j++) {
        cost = min(cost,fts(j) + abs(p[j] - p[i]));
    }
    
    return dp[i] = cost;
}
void solve() {
    cin >> n >> k;
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
