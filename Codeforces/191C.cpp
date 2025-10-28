#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
vector<pair<int,int>>g[100005];
int dp[20][100005],depth[100005],ans[100005],cnt[100005];

void binarylifting(int node , int parent,int cnt=0) {
    dp[0][node] = parent;
    for(int i = 1;i < 20;i++) {
        dp[i][node] = dp[i-1][ dp[i-1][node] ]; // parent[parent[n/2]]
    }
    depth[node] = cnt;

    // for(auto e:g[node]) {
    //     if(e == parent) continue;
    //     binarylifting(e,node,cnt+1);
    // }
    for(auto [to, id] : g[node]) {
        if (to == parent) continue;
        binarylifting(to, node, cnt + 1);
    }

}
int kthparent(int node,int k) {
    int p = 0;
    while (k)
    {
        if(k&1) {
            node = dp[p][node];
        }
        k >>= 1;
        p++;
    }
    // for(int i = 19; i >= 0; i--) {
    //     if(k & (1<<i)) {
    //         node = dp[i][node];
    //     }
    // }
    return node;
}
int lca(int u,int v) {
    if(depth[u] > depth[v]) {
        swap(u,v);
    }
    v = kthparent(v , abs(depth[v] - depth[u]));
    // depth of u is always small
    if(u == v) {
        return u;
    }

    for(int i = 19; i >=0; i--) {
        if(dp[i][u] != dp[i][v]) {
            u = dp[i][u];
            v = dp[i][v];
        }
    }
    return dp[0][u];
    return dp[0][v];
}
int dist(int u,int v) {
    int lc = lca(u,v);
    return depth[u] + depth[v] - 2 * depth[lc];
}
void dfs(int node, int parent) {
    for (auto [to, idx] : g[node]) {
        if (to == parent) continue;
        dfs(to, node);
        cnt[node] += cnt[to];
        ans[idx] = cnt[to];
    }
}
void solve() {
    int n; cin >> n;
    for(int i = 0; i < n-1; i++) {
        int u,v; cin >> u >> v;
        g[u].push_back({v,i});
        g[v].push_back({u,i});
    }

    binarylifting(1,0);
    int k; cin >> k;
    while (k--)
    {
        int u,v; cin >> u >> v;
        cnt[u]++;
        cnt[v]++;
        ll nts = lca(u,v);
        cnt[nts]-=2;
    }
    dfs(1,0);
    for (int i = 0; i < n - 1; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
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
