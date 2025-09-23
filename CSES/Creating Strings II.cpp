#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int Max = 1e6;
ll fact[Max+1] , factInv[Max+1];
const int mod = 1e9 + 7;

// modular inverse b = (b)^-1 = Pow(b,m-2);
// Need to call build_fact() first
ll Pow(ll a,ll b){
    ll ans = 1;
    while(b>0){
        if(b&1) ans=(ans*a) % mod;
        b>>=1;
        a=(a*a) % mod;
    }
    return ans;
}

void build_fact() {
    fact[0] = 1;
    for(int i = 1; i <= Max; i++)
    {
        fact[i] = 1LL * fact[i - 1] * i % mod;
    }
    factInv[Max - 1] = Pow(fact[Max - 1], mod - 2);
    for(int i = Max - 2; i >= 0; i--)
    {
        factInv[i] = 1LL * factInv[i + 1] * (i + 1) % mod;
    }
    return;
}

ll nCr_mod(int n, int r) {
    if(n < r or n < 0 or r < 0) return 0;
    return 1LL * fact[n] * factInv[r] % mod * factInv[n - r] % mod;
}

int nPr_mod(int n, int r) { // nPr = nCr * r! 
    if(n < r or n < 0 or r < 0) return 0;
    return (1LL * nCr_mod(n, r) * fact[r]) % mod;
}
void solve() {
    string s; cin >> s;
    int n = s.size();
    ll  first = fact[n];
    map<char,int>Mp;
    for(int i =  0 ; i < n ; i++) {
        Mp[s[i]]++;
    }
    ll dividend = 1;
    
    for(auto &i : Mp) {
        dividend  = (dividend * factInv[i.second] ) % mod;
    }
    ll ans = (first * dividend) % mod;
    cout << ans << endl;
}

int main() {
    fast
    build_fact();
    ll t=1;//cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
