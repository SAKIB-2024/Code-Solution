#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N = 1e6 + 10;
int dp[N];

ll NTS(int i){
    if(i == 0) return 0;
    if(dp[i] != -1) return dp[i];
    ll cost = 1e18;
    string s = to_string(i);
    for(int j = 0; j < s.size();j++) {
        if(s[j]-'0' == 0) continue;
        cost = min(cost , NTS(i - (s[j]-'0'))+1);
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
