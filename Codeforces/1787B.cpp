#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int mod = 1e9+7;

void solve() {
    int n; cin >>n ;
    map<int,int>mpp;
    ll k = sqrtl(n);
    ll j = n;
    for(int i = 2; i <= k; i++) {
        while (j % i == 0)
        {
            j /= i;
            mpp[i]++;
        }
        
    }
    if(j > 1) {
        mpp[j]++;
    }
    ll real = 0;
    while (true)
    {
        ll fact = 1;
        ll mn = 1e18;
        for(auto [x,y] : mpp){
            if(y > 0){
                fact *= x;
                mn = min(mn , 1LL*y);
            }
        }
        if(fact == 1) break;
        real += (fact * mn);
        for(auto &[x,y]:mpp){
            y -= mn;
        }
    }
    

    cout << real << endl;
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
