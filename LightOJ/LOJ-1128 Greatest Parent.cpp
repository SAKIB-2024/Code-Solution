// Problem Link : https://lightoj.com/problem/greatest-parent
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N = 1e5+10;
vector<int>g[N];
int dp[20][N],depth[N];

void binarylifting(int node , int parent,int cnt=0) {
    dp[0][node] = parent;
    for(int i = 1;i < 20;i++) {
        dp[i][node] = dp[i-1][ dp[i-1][node] ]; // parent[parent[n/2]]
    }
    depth[node] = cnt;

    for(auto e:g[node]) {
        if(e == parent) continue;
        binarylifting(e,node,cnt+1);
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
int gg(int u,int k, vector<int>&p) {
    for(int i = 19; i >=0 ; i--) {
        if(p[dp[i][u]] >=  k) {
            u = dp[i][u];
        }
    }
    return u;
}
// int dist(int u,int v) {
//     int lc = lca(u,v);
//     return depth[u] + depth[v] - 2 * depth[lc];
// }
void solve(int t) {
    int n,q; cin >> n >> q;
    for (int i = 0; i <= n; i++) {
        g[i].clear();
        for (int j = 0; j < 20; j++) dp[j][i] = 0;
        depth[i] = 0;
    }
    vector<int>val(n);
    val[0] = 1;
    for(int i = 1; i < n; i++) {
        ll u,v; cin >> u >> v;
        g[u].push_back(i);
        g[i].push_back(u);
        val[i] = v;
    }
    binarylifting(0,0);
    cout << "Case " << t <<":" << endl;
    while (q--)
    {
        int u, v; cin >> u >> v;
        //int lc = lca(u,v);
        int lc = gg(u, v , val);
        cout << lc << endl;
    }
    
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; cin >> t;
    for(int i = 1 ; i <= t; i++) {
        solve(i);
    }
    return 0;
}
