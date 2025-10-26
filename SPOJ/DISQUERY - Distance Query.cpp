#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 10;
const int LOG = 20;

vector<pair<int,int>> g[N]; // adjacency list: {neighbor, weight}
int up[LOG][N];              // 2^i-th ancestor
int minw[LOG][N];            // min weight to 2^i-th ancestor
int maxw[LOG][N];            // max weight to 2^i-th ancestor
int depth[N];

void dfs(int node, int parent, int w = 0, int d = 0) {
    up[0][node] = parent;
    minw[0][node] = w;
    maxw[0][node] = w;
    depth[node] = d;

    for(int i = 1; i < LOG; i++) {
        int mid = up[i-1][node];
        up[i][node] = up[i-1][mid];
        minw[i][node] = min(minw[i-1][node], minw[i-1][mid]);
        maxw[i][node] = max(maxw[i-1][node], maxw[i-1][mid]);
    }

    for(auto [nei, wt] : g[node]) {
        if(nei == parent) continue;
        dfs(nei, node, wt, d + 1);
    }
}

int kthparent(int node, int k) {
    for(int i = 0; i < LOG; i++) {
        if(k & (1 << i)) node = up[i][node];
    }
    return node;
}

int lca(int u, int v) {
    if(depth[u] > depth[v]) swap(u, v);
    v = kthparent(v, depth[v] - depth[u]);
    if(u == v) return u;

    for(int i = LOG-1; i >= 0; i--) {
        if(up[i][u] != up[i][v]) {
            u = up[i][u];
            v = up[i][v];
        }
    }
    return up[0][u];
}

pair<int,int> query(int u, int v) {
    int lc = lca(u,v);
    int mn = INT_MAX, mx = 0;

    auto lift = [&](int node, int k) {
        int res_min = INT_MAX, res_max = 0;
        for(int i = LOG-1; i >= 0; i--) {
            if((1 << i) <= k) {
                res_min = min(res_min, minw[i][node]);
                res_max = max(res_max, maxw[i][node]);
                node = up[i][node];
                k -= (1 << i);
            }
        }
        return make_pair(res_min, res_max);
    };

    auto [mn1, mx1] = lift(u, depth[u] - depth[lc]);
    auto [mn2, mx2] = lift(v, depth[v] - depth[lc]);

    mn = min(mn1, mn2);
    mx = max(mx1, mx2);
    return {mn, mx};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    for(int i = 1; i < n; i++) {
        int a,b,c; cin >> a >> b >> c;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }

    dfs(1, 0); // root at 1

    int q; cin >> q;
    while(q--) {
        int u,v; cin >> u >> v;
        auto [mn, mx] = query(u,v);
        cout << mn << ' ' << mx << '\n';
    }

    return 0;
}
