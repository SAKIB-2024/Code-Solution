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

void solve() {
    int n,k; cin >> n >> k;
    string temp; cin >> temp;
    string s;
    while (s.size() < k) s += temp;    
    int j = 0;
    for(int i = 1 ; i < n; i++) {
        if(s[i] < s[0]) {
            j = i;
        }
        else if(s[i] == s[0]) {
            j = i - 1;
            int l = 0, r = i;
            while (r < n)
            {
                ++l;
                ++r;
                if(s[r] < s[l]) {
                    j = r;
                    i = r;
                    goto NanaBari;
                }
                else if(s[r] > s[l]) {
                    goto Gym;
                }
            }
            
        }
        else {
            break;
        }
        NanaBari:
    }
    Gym:
    string trk = s.substr(0,j+1);
    j = 0;
    int sz = trk.size();
    string ans;
    while (ans.size() < k)
    {
        ans.push_back(trk[j]);
        j++;
        j %= sz;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
