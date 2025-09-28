//https://codeforces.com/gym/103860/problem/F
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    vector<ll>p(n),q,visited(n,0);
    bool ok = true;
    for(int i = 0 ;i < n;i++) {
        cin >> p[i];
        if(p[i] == 1){
            ok = false;
        }
    }
    ll x; cin >> x;
    if(!ok){
        cout << 0 << endl;return 0;
    }
    sort(p.rbegin(),p.rend());
    ll mn = p.back();
    ll ans = 0;
    for(int mask = 1 ; mask < (1 << n);mask++ ){
        ll temp = x;
        for(int i= 0;i < n;i++){
            if(mask & (1 << i)){
                temp %= p[i];
            }
        }
        for(int i= 0;i < n;i++){
            if(! (mask & (1 << i))){
                temp %= p[i];
            }
        }

        ans = max(ans, temp);
    }
    cout << ans << endl;
    return 0;
}
