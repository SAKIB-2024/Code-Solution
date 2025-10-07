#include<bits/stdc++.h>
using namespace std;
#define ll long long
int query(int l, int r) {
    if (l >= r) return -1;
    cout << "? " << l + 1 << ' ' << r + 1 << endl;
    int ans;
    cin >> ans;
    return ans - 1;
}
void solve() {
    int n; cin >> n;
    ll l = 0,h = n;
    ll x,left,right;
    while (h - l > 1)
    {
        ll mid = (l + h) / 2;
        ll k = query(l , h-1);
        if(k < mid) {
            if(query(l,mid - 1) == k) {
                h = mid;
            }
            else{
                l = mid;
            }
        }
        else{
            if(query(mid, h - 1) == k) {
                l = mid;
            }
            else{
                h = mid;
            }
        }
    }
    cout <<"! "<< h << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
