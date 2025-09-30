#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    vector<int>p(n);
    ll ans = 0;
    for(int i = 0 ; i < n; i++){
        cin >> p[i];
        ans += p[i]-1;
    }

    cout << ans << endl;
    return 0;
}
