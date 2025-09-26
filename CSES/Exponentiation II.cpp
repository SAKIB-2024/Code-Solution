#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll mod = 1e9+7;
long long Pow(ll a,ll b,ll mo){
    ll ans = 1;
    while(b>0){
        if(b&1) ans=(ans*a)%mo;
        b>>=1;
        a=(a*a)%mo;
    }
    return ans;
}
void solve() {
    int a,b,c; cin >> a >> b >> c;
    ll first = Pow(b ,c , mod - 1);
    ll no = Pow(a, first , mod);
    cout << no << endl;
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
