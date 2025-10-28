#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
vector<pair<int,int>>g[2010];
int dp[20][2010],depth[2010];
int p[2010][2010];
int w[2010];
struct Q{
    int w, u, v;
};

struct DSU {
    vector<int> par, sz;
    int c;
    DSU(int n) {
        par.resize(n + 1); sz.resize(n + 1); c = n;
        for(int i = 1; i <= n; i++) par[i] = i, sz[i] = 1;
    }
    int findpar(int u) {
        if(par[u] == u) return u;
        return par[u] = findpar(par[u]);
    }
    int count() { return c; }
    bool Unioned(int u, int v) {
        int a = findpar(u);
        int b = findpar(v);
        if(a == b) return false;
        if(sz[a] < sz[b]) swap(a, b);
        par[b] = a;
        sz[a] += sz[b];
        --c;
        return true;
    }
};

bool cmp (const Q &a, const Q&b) {
    return a.w < b.w;
}
void solve() {
    int n; cin >> n;
    bool ok = true;
    vector<Q>edge;
    for(int i = 1; i <= n; i++) {
        for(int j = 1 ; j <= n ; j++) {
                int k; cin >> k;
                if(i == j && k != 0) {
                    ok = false;
                }
                else if(i != j && k == 0) {
                    ok = false;
                }
                else{
                    p[i][j] = k;
                    // g[i].push_back({j,k});
                    // g[j].push_back({i,k});
                }

                if(i != j) {
                    edge.push_back({k, i , j});
                }
        }
    }
    for(int i = 1 ; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(p[i][j] != p[j][i]) {
                ok = false;
            }
        }
    }
    if(!ok) {
        cout << "NO" << endl;return;
    }

    sort(edge.begin() , edge.end() , cmp) ;
    DSU dsu(n);

    for(auto i : edge) {
        ll k = i.u;
        ll j = i.v;
        ll m = i.w;

        if(dsu.Unioned(k , j)) {
            g[k].push_back({j , m});
            g[j].push_back({k , m});
        }
    }

    vector<vector<int>>visited(n+1 , vector<int>(n+1 , -1));
    for(int i = 1 ; i <= n; i++) {
        queue<int>q;
        q.push(i);
        visited[i][i] = 0;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for(auto [v,w] : g[u]) {
                if(visited[i][v] == -1) {
                    visited[i][v] = visited[i][u] + w;
                    q.push(v);
                }
            }
        }
        
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(visited[i][j] != p[i][j]) {
                cout << "NO" << endl;return;
            }
        }
    }
    cout << "YES" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
