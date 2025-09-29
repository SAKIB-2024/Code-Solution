// Problem Link : https://codeforces.com/contest/987/problem/B
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define i128 __int128
#define endl '\n'
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int x,y; cin >> x >> y;
    double a = x * log(y);
    double b = y * log(x);
    if(a == b){
        cout << '=' ;
    }
    else if(a > b){
        cout <<'<';
    }
    else cout << '>';
    return 0;
}
