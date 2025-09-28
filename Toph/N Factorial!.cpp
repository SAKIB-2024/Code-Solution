// https://toph.co/p/n-factorial
#include <bits/stdc++.h>
using namespace std;

const int N = 102, mod = 10000;
int fact[N];

void precal() {
    fact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = 1LL * fact[i - 1] * i % mod;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    precal();
    int tc; cin >> tc;
    while (tc--) {
        long long n; cin >> n;
        string s;
        if (n >= 20) s = "0";     
        else s = to_string(fact[n]);
        while (s.size() < 4) s = '0' + s;   
        cout << s << "\n";          
    }
}
