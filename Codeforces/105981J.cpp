// PROBLEM LINK : https://codeforces.com/gym/105981/problem/J
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve(vector<double>&p) {
    int n; cin >> n;
    cout << fixed << setprecision(15) << p[n] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<double>p(1e5+1,0.0);
    double ans = 0.0;
    for(int i = 1; i <= 1e5; i++) {
        p[i] += (double) 1 / i +(p[i-1]);
    }
    int t = 1; cin >> t;
    while(t--){
        solve(p);
    }
    return 0;
}
