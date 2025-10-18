#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll query(int type, int l, int r) {
    cout << type << " " << l << " " << r << endl;
    cout.flush();
    ll res; cin >> res;
    return res;
}
void solve() {
    int n; cin >> n;
    ll l = 1,h = n;
    ll k = query(1, l, h);
    ll j = query(2, l, h);

    ll dif = j - k;
    if(dif == n) {
        cout << "! "<<l <<" "<< h << endl;
        cout.flush();
        return;
    }
    ll right = n;
    while (l <= h)
    {
        ll mid = (l + h) >> 1;
        ll left1 = query(1, 1, mid);
        ll left2 = query(2 , 1 , mid);
        
        ll d = abs(left1 - left2);
        if(d < dif) {
            l = mid + 1;
        }
        else {
            right = mid ;
            h = mid - 1;
        }

    }
    ll left = right - dif + 1;
    cout << "! " << left << ' ' << right << endl;
    cout.flush();    
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
