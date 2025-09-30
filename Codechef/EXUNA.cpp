//Problem Link :- https://www.codechef.com/problems/EXUNA
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
    int n; cin >>n;
    vector<int>p(n);
    ll mn = 1e18;
    for(int i = 0 ; i < n; i++) {
        cin >> p[i];
        mn = min(mn,1LL*p[i]);
    }
    cout << mn << endl;

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
