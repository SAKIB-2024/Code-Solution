// Problem Link :- https://www.codechef.com/START208C/problems/GUCD
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
    int n; cin >> n;
    vector<int>p(n);
    ll mx = 0;
    ll mn = 1e18;
    map<int,int>mpp;

    for(int i = 0 ; i < n; i++) {
        cin >> p[i];
        mpp[p[i]]++;
        mn = min(mn , 1LL*p[i]);
        mx = max(mx , 1LL*p[i]);
    }
    
    for(int i = mx -1 ; i >= 0 ;i-- ) {
        if(mx % i != 0 && mn% i != 0) {
            cout << i << endl;return;
        }
    }
    
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
