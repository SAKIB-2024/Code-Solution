#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N = 1e6 + 10;
const int mod = 1e9+7;
int dp[N];

ll NTS(int i){
    if(i == 0) return 1;
    if(dp[i] != -1) return dp[i];
    ll cost = 0;
    for(int j = 1; j <= 6;j++) {
        if(i >= j ) {
            cost += NTS(i - j);
            cost %= mod;
        }
        else{
            break;
        }
    }
    return dp[i] = cost;
}

void solve() {
    int n; cin >> n;
    memset(dp,-1,sizeof(dp));
    cout << NTS(n) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;// cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
