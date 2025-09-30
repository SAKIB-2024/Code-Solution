#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    while (cin >> n >> m) {
        ll res = 1;
        for (int i = 0; i < m; i++) {
            res *= (n - i);
            while (res % 10 == 0) res /= 10;  
            res %= 1000000000;              
        }
        cout << res % 10 << "\n";
    }
    return 0;
}
