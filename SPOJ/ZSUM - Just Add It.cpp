//Problem Link :- https://www.spoj.com/problems/ZSUM/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

long long Pow(ll a,ll b,ll mod){
    ll ans = 1;
    while(b>0){
        if(b&1) ans=(ans*a)%mod;
        b>>=1;
        a=(a*a)%mod;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int mod = 1e7+7;
    int n , k;
    while (cin >> n >> k)
    {
        if(n == 0 && k == 0) return 0;
        ll sn = Pow(n, k, mod);
        ll sn1 = Pow(n-1, k, mod);
        sn  = (sn + (2*sn1)) % mod;
        ll pn = Pow(n, n, mod);
        ll pn1 = Pow(n-1 , n-1 , mod);
        pn = (pn + (2*pn1)) % mod;
        ll ans = (sn + pn) % mod;
        cout << ans << endl;
    }
    
    return 0;
}
