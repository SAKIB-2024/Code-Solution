#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define print(v) for(auto e:v) cout<<e<<" "; cout<<endl;

void solve() {
    int n , x, y; cin >> n >> x >> y;
    if(x > 0 && y > 0) {
        cout << -1 << endl;
    }
    else if(x == 0 && y == 0) {
        cout << -1 << endl;
    }
    else {
        if(x == 0) swap(x,y);
        vector<int>p;
        if((n-1) % x != 0) {
            cout << -1 << endl;
        }
        else {
            ll k = n-1 / x ;
            ll trk = 1;
            ll cnt = 0;
            for(int i = 1 ; i < n;i++) {
                if(cnt < x) {
                    cout << trk << ' ';
                    cnt++;
                }
                else if(cnt == x) {
                    trk = i+1;
                    cnt =  1;
                    cout << trk << ' ';
                }
            }
            cout << endl;
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
