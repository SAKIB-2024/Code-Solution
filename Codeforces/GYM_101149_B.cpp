//Problem LINK :- https://codeforces.com/gym/101149/problem/B
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
struct Q{
    ll diff,a,b;
};

bool cmp(const Q & a, const Q &b){
    if(a.diff != b.diff){
        return a.diff > b.diff;
    }
    return a.diff > b.diff;
}
void solve() {
    int n; cin >> n;
    vector<Q>p;
    for(int i = 0 ; i < n; i++) {
        ll a,b; cin >> a >> b;
        ll dif = a - b;
        p.push_back({dif,a,b});
    }
    sort(p.begin(),p.end(),cmp);
    ll ans = 0;
    ll reserve = 0;
    for(auto i:p){
        if(i.a > reserve){
            ans += i.a - reserve;
            reserve = i.diff;
        }
        else{
            reserve -= i.a;
            reserve += i.diff;
        }
        
    }
    cout << ans << endl;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
