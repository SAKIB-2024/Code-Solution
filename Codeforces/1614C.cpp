#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <array>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <cstring>
#include <climits>
#include <cfloat>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <bitset>
#include <iterator>
#include <utility>
#include <tuple>
#include <sstream>
#include <cassert>
#include <random>
#include <chrono>
#include <complex>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
#define print(v) for(auto e:v) cout<<e<<" "; cout<<endl;
const int N = 1e9+7;

void solve() {
    ll n , m; cin >> n >> m;
    vector<ll>p(n);
    ll total = 0;
    while (m--)
    {
        ll l , r, x; cin >> l >> r >> x;
        total |= x;
    }
    ll ans = 1;
    for(int i = 1; i < n; i++) {
        ans = (ans * 2) % N;
    }
    ll sum = ans * total % N;
    cout << sum << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; cin >> t;
    for(int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}
