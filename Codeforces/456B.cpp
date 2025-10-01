// Problem Link :- https://codeforces.com/problemset/problem/456/B
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

long long Pow(ll a,ll b){
    ll ans = 1;
    while(b>0){
        if(b&1) ans=(ans*a)%5;
        b>>=1;
        a=(a*a)%5;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;cin >> s;
    ll k =0;
    if(s.size()>1){
        string x =s.substr(s.size()-2);
        k = stoll(x);
    }
    else{
        k = stoll(s.substr(s.size()-1));
    }
    
    ll ans = 0;
    for(int i = 1 ;i < 5 ;i++) {
        ans += Pow(i,k);
        //cout << ans << endl;
    }
    cout << ans % 5 << endl;
    return 0;
}
