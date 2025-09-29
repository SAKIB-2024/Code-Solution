// https://codeforces.com/contest/1603/problem/B
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define i128 __int128

void solve() {
    int x,y ; cin >> x >> y;
    if(y%x == 0) {
        cout << x << endl;return;
    }
    if(x > y){
        cout << (x + y) << endl;return;
    }
    ll k = (x + y) / 2 ;
    if(k%x == y%k){
        cout << k << endl;
    }
    else{
        ll j = k % x;
        cout << y - j << endl; 
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
