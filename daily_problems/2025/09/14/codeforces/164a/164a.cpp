#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    vector<int> f(n);
    for (int i = 0; i < n; i++) {
        cin >> f[i];
    }
    
    vector<vector<int>> adj(n), radj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        radj[v].push_back(u);
    }
    
    queue<int> q;
    vector<int> vis(n);
    for (int i = 0; i < n; i++) {
        if (f[i] == 1) {
            q.push(i);
            vis[i] |= 1;
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (f[v] != 1 && (vis[v] & 1) == 0) {
                q.push(v);
                vis[v] |= 1;
            }
        }
    }
    
    q = queue<int>();
    for (int i = 0; i < n; i++) {
        if (f[i] == 2) {
            vis[i] |= 2;
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (f[u] == 1) {
          continue;
        }
        for (int v : radj[u]) {
            if ((vis[v] & 2) == 0) {
                q.push(v);
                vis[v] |= 2;
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        cout << (vis[i] == 3 ? 1 : 0) << "\n";
    }
    
    return 0;
}