#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define print(v) for(auto e:v) cout<<e<<" "; cout<<endl;

void solve() {
    int n; cin >> n;
    vector<int>p(n),q(n),a;
    for(int i = 0 ; i < n; i++) {
        cin >> p[i];
    }
    q[0] = p[0];
    for(int i = 1;i < n; i++) {
        if(p[i] && p[i] <= q[i-1]){
            cout << -1 << endl;return;
        }
        q[i] = p[i] + q[i-1]; 
    }
    print(q);

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
