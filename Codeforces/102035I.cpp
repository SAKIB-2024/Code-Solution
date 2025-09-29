// Problem Link :- https://codeforces.com/gym/102035/problem/I
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    vector<ll>p(n),q;
    for(int i = 0; i < n ;i++) {
        cin >> p[i];
    }
    q = p;
    reverse(q.begin() , q.end());
    if(p == q) {
        cout << -1 << endl;return 0;
    }
    int ans = 0;
    for(int i = 0 ; i < n/2 ;i++) {
        int k = abs(p[i] - p[n - i - 1]);
        ans = __gcd( k, ans);
    }
    cout << ans << endl;
    return 0;
}
