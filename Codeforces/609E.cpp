// First MST Than LCA
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N = 200005;
const int LOG = 20;

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

struct Edge {
    int u, v, w, idx;
};

int n, m;
vector<pair<int, int>> g[N];
int dp[LOG][N], mx[LOG][N], depth[N];

void binarylifting(int node, int parent, int weight, int cnt = 0) {
    dp[0][node] = parent;
    mx[0][node] = weight;
    depth[node] = cnt;
    for(int i = 1; i < LOG; i++) {
        dp[i][node] = dp[i - 1][dp[i - 1][node]];
        mx[i][node] = max(mx[i - 1][node], mx[i - 1][dp[i - 1][node]]);
    }
    for(auto [e, w] : g[node]) {
        if(e == parent) continue;
        binarylifting(e, node, w, cnt + 1);
    }
}

int kthparent(int node, int k) {
    int p = 0;
    while(k) {
        if(k & 1) node = dp[p][node];
        k >>= 1;
        p++;
    }
    return node;
}

int lca(int u, int v) {
    if(depth[u] > depth[v]) swap(u, v);
    int diff = depth[v] - depth[u];
    for(int i = 0; i < LOG; i++){
        if (diff & (1 << i)) {
            v = dp[i][v];
        }
    }
    if(u == v) return u;
    for(int i = LOG - 1; i >= 0; i--) {
        if(dp[i][u] != dp[i][v]) {
            u = dp[i][u];
            v = dp[i][v];
        }
    }
    return dp[0][u];
}

int gg(int u, int v) {
    int lc = lca(u, v);
    int res = 0;
    int diff = depth[u] - depth[lc];
    for (int i = 0; i < LOG; i++)
        if (diff & (1 << i)) {
            res = max(res, mx[i][u]);
            u = dp[i][u];
        }
    diff = depth[v] - depth[lc];
    for (int i = 0; i < LOG; i++)
        if (diff & (1 << i)) {
            res = max(res, mx[i][v]);
            v = dp[i][v];
        }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        edges[i].idx = i;
    }
    sort(edges.begin(), edges.end(), [](auto &a, auto &b) { return a.w < b.w; });
    DSU dsu(n);
    vector<char> used(m, 0);
    ll sum = 0;
    for(auto &e : edges) {
        if(dsu.Unioned(e.u, e.v)) {
            used[e.idx] = 1;
            sum += e.w;
            g[e.u].push_back({e.v, e.w});
            g[e.v].push_back({e.u, e.w});
        }
    }
    binarylifting(1, 0, 0);
    vector<ll> ans(m);
    for (auto &e : edges) {
        if(used[e.idx]) {
            ans[e.idx] = sum;
        }
        else {
            int mx = gg(e.u, e.v);
            ans[e.idx] = sum - mx + e.w;
        }
    }
    for(int i = 0; i < m; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}
