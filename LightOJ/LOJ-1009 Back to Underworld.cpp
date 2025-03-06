#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<ll>
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

map<ll, vi> graph;          // Adjacency list
map<ll, bool> visited, node_typ; // To handle arbitrary node IDs

ll mod_bfs(ll start) {
    ll lykan = 0, vam = 0;
    queue<ll> q;
    q.push(start);
    visited[start] = true;
    node_typ[start] = true; // Start node as lykan
    lykan++;

    while (!q.empty()) {
        ll u = q.front();
        q.pop();

        for (ll v : graph[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
                if (node_typ[u]) { // Parent is lykan
                    node_typ[v] = false; // Mark as vampire
                    vam++;
                } else {
                    node_typ[v] = true; // Mark as lykan
                    lykan++;
                }
            }
        }
    }

    return max(lykan, vam); // Return maximum of lykan and vampire counts
}

void solve(ll cnt) {
    ll n;
    cin >> n;

    // Reset state for new test case
    graph.clear();
    visited.clear();
    node_typ.clear();

    for (ll i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    ll total = 0;

    // Process each connected component
    for (const auto& [node, _] : graph) {
        if (!visited[node]) {
            total += mod_bfs(node);
        }
    }

    cout << "Case " << cnt << ": " << total << '\n';
}

int main() {
    fast
    ll t;
    cin >> t;
    for (ll i = 1; i <= t; i++) {
        solve(i);
    }
    return 0;
}
