#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
#define print(v) for(auto e:v) cout<<e<<" "; cout<<endl;
const int N = 2e5+7, mod = 1e9+7;

void solve(int t) {
    int n; cin >> n ;
    vector<int> p(n), ans(n);

    for(int i = 0; i < n; i++) {
        cin >> p[i];
    }
    for(int i = 0; i < n-1; i+=2) {
        ll k = p[i] * p[i + 1];
        ans[i] = p[i + 1] * -1;
        ans[i + 1] = p[i];
    }
    if(n & 1) {
        ll x = p[n - 3];
        ll y = p[n - 2];
        ll z = p[n - 1];
        if(x + y != 0) {
            ans[n - 1] = (x + y) * -1;
            ans[n - 2] = p[n - 1];
            ans[n - 3] = p[n - 1];
        }
        else if(x + z != 0) {
            ans[n - 2] = (x + z) * -1;
            ans[n - 1] = p[n - 2];
            ans[n - 3] = p[n - 2];
        }
        else if(z + y != 0) {
            ans[n - 3] = (z + y) * -1;
            ans[n - 1] = p[n - 3];
            ans[n - 2] = p[n - 3]; 
        }

    }
    print(ans);
    

    
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; cin >> t;
    for(int i = 0; i < t; i++) {
        solve(i+1);
    }
    return 0;
}
