#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
#define print(v) for(auto e:v) cout<<e<<" "; cout<<endl;
#define printp(v) for(auto e:v) cout<<e.first<<" "<<e.second<<endl;

void solve() {
    int n,k; cin >> n >> k;
    string s; cin >> s;
    string ans(k,'z');
    for(int i = 1; i <= n; i++) {
        string m = s.substr(0,i);
        ll sz = m.size();
        ll j = 0;
        string moat = "";
        for(int x = 0 ; x < k; x++) {
            if(sz == j) {
                j = 0;
            }
            moat += m[j];
            j++;
        }
        ans = min(ans , moat);
    }
    cout << ans << endl;
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
