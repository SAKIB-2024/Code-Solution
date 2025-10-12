#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
    int n; cin >> n;
    vector<int>p(n);
    map<ll,ll>Mp;
    for(int i = 0 ; i < n;i++) {
        cin >>p[i];
        Mp[p[i]]++;
    }

    ll side = 0 , sum = 0;
    vector<ll>s;
    for(auto [x,y] : Mp) {
        if(y&1) {
            side += (y-1);
            sum += (y-1) * x;
            s.push_back(x);
        }
        else{
            side += y;
            sum += (x*y);
        }
    }
    ll trk = 0;
    ll len = s.size();
    for(int i = len-1;i >= 0 ; i--) {
        if(trk >= 2) {
            break;
        }
        if(sum > s[i]) {
            sum += s[i];
            side++;
            trk++;
        }
        else{
            ll k = s[i];
            ll j = sum;
            if(i-1 >= 0) {
                j += s[i-1];
            }
            if(j > k) {
                sum += s[i] + s[i-1];
                side += 2;
                break;
            }
            
        }
    }

    if(side >= 3) {
        cout << sum << endl;
    }
    else {
        cout << 0 << endl;
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
