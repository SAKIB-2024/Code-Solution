#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
ll get_mex(map<int,int>&Mp){
    int cnt = 0;
    while (Mp[cnt]>0)
    {
        cnt++;
    }
    return cnt;
    
}

ll get_vec(map<int,int>& Mp, vector<int>& p) {
    int Mex = get_mex(Mp);
    map<int,int> temp = Mp;
    ll trk = 0;
    for (int i = 0; i < (int)p.size(); i++) {
        if(p[i] > Mex || (p[i] < Mex && Mp[p[i]] > 1)){
            trk += Mex;
            temp[p[i]]--;
            if (temp[p[i]] == 0) temp.erase(p[i]);
            p[i] = Mex;
            temp[Mex]++;
        }
        else{
            trk += p[i];
        }
    }
    Mp = temp;
    return trk;
}

void solve() {
    int n, k ; cin >> n >> k;
    vector<int>p(n);
    map<int,int>Mp;
    for(int i = 0; i < n; i++) {
        cin >> p[i];
        Mp[p[i]]++;
    }
    ll sum1 = 0, sum2 = 0, sum3 = 0;
    for(int i =  0 ; i < 3 ; i++) {
        ll ki = get_vec(Mp,p);
        if(i == 0){
            sum1 = ki;
        }
        if(i == 1) sum2 = ki;
        else sum3 = ki;
    }

    if(k == 1){
        cout << sum1 << endl;
    }
    else if((k - 2) % 2 == 0){
        cout << sum2 << endl;
    }
    else{
        cout << sum3 << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;  cin >> t;
    while(t--){
        solve();
    }
    return 0;
}