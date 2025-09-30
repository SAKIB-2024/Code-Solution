// Problem Link :- https://codeforces.com/contest/1932/problem/D
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
    int n; cin >> n;
    char c; cin >> c;
    vector<multiset<string>>Mp(256);
    for(int i = 0; i < n*2; i++){
        string s ; cin >> s;
        Mp[s[1]].insert(s);
    }
    vector<string>need;
    vector<char>nts={'C','D','H','S'};
    for(char i :nts){
        if(i != c){
            ll cnt =0;
            for(string j:Mp[i]){
                need.push_back(j);
                cnt++;
            }
            if((cnt%2==1)){
                if(Mp[c].empty()){
                    cout << "IMPOSSIBLE" << endl;return;
                }
                string k = *Mp[c].begin();
                auto it = Mp[c].find(k);
                if(it != Mp[c].end()){
                    Mp[c].erase(it);
                }
                need.push_back(k);
            }
        }
    }
    ll cnt = 0;
    for(string i:Mp[c]){
        need.push_back(i);
    }
    if(need.size() == n*2){
        for(string i:need){
            cout<< i << ' ';
            cnt++;
            if(cnt %2 ==0) cout<< endl;
        }
    }
    else{
        cout <<"IMPOSSIBLE" << endl;
    }
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
