// Problem Link :- https://codeforces.com/contest/1379/problem/B
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
    ll l,r,m; cin >> l >> r >> m;
    ll mx = r-l;
    for(int i = l ;i <= r;i++) {
        if(m % i == 0){
            cout << i << ' ' << i << ' '<< i << endl;return;
        }
        else{
            ll nts = m / i;
            ll need = m - (nts*i);
            if(need <= mx){
                if(m <= l) {cout << i << ' ' << i << ' '<< (i+i)-m  << endl;return;}
                else{
                    cout << i << ' ' << r << ' '<< r - need << endl;return;
                }
            }
            else{
                ll k = ((nts+1) * i ) - m;
                if(k <= mx){
                    cout << i << ' ' << r - k << ' ' << r << endl;return;
                }
            }
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
