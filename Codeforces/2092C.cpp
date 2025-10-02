#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
    int n; cin >> n;
    vector<int>p(n);
    ll sum = 0;
    ll odd = 0 , even = 0;
    for(int i = 0 ; i<n ;i++) {
        cin >> p[i];
        sum += p[i];
        if(p[i] & 1) odd++;
        else even++;
    }
    sort(p.begin(),p.end());
    if(odd == 0 || even == 0) {
        cout << p[n-1] << endl;return;
    }
    if(p[n-1] & 1){
        sum -= (odd-1);
    }
    else{
        sum -= (odd - 1);
    }
    cout << sum << endl;
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
