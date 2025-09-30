// Problem Link :- https://codeforces.com/contest/1848/problem/B
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
    int n,k; cin >> n >> k;
    vector<int>p(n);
    map<int,int>Mp;
    map<int,multiset<int>>mpp;
    for(int i = 0; i < n;i++) {
        cin >> p[i];
        ll k = i+1 - Mp[p[i]] -1;
        mpp[p[i]].insert(k);
        Mp[p[i]] = i+1;
    }
    ll mn = 1e16;
    for(auto [x,y] : mpp){
        ll k = n - Mp[x];
        mpp[x].insert(k);
        ll j = *mpp[x].rbegin();
        auto it = mpp[x].find(j);
        if(it != mpp[x].end()){
            mpp[x].erase(it);
        }
        j /= 2;
        mpp[x].insert(j);
        j = *mpp[x].rbegin();
        mn = min(mn , j);
    }
    cout << mn << endl;
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
