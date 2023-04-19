#include<bits/stdc++.h>
#define int long long
#define inf 1e10l
using namespace std;


struct edge { int u, v, c; };
vector<pair<int, int>> gp[2002];
vector<edge> g;
vector<int> d(2002, -inf), p(2002, -1), used(2002, 0), ban(2002, 0);

void bfs(int i, int c) {
    used[i] = c;
    for (auto& e : gp[i]) {
        if (!used[e.first]) bfs(e.first, c);
    }
}

int32_t main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        edge ins;
        cin >> ins.u >> ins.v >> ins.c;
        ins.u--; ins.v--;
        gp[ins.v].emplace_back(ins.u, ins.c);
        g.push_back(ins);
    }
    d[0] = 0;
    for (int k = 0; k < n; k++) {
        for (auto& e : g) {
            if (d[e.u] > -inf && d[e.v] < d[e.u] + e.c) {
                d[e.v] = d[e.u] + e.c;
                p[e.v] = e.u;
            }
        }
    }

    if (d[n - 1] == -inf) {
        cout << ":(";
        return 0;
    }
    bfs(n - 1, 1);

    int u = 2002;
    while (u != -1) {
        u = -1;
        for (auto& e : g) {
            if (!ban[e.u] && !ban[e.v]) {
                if (d[e.u] > -inf && d[e.v] < d[e.u] + e.c) {
                    d[e.v] = d[e.u] + e.c;
                    p[e.v] = e.u;
                    u = e.u;
                }
            }
        }
        if (u == -1) continue;
        vector<int> cyc;
        int y = u;
        for (int i = 0; i < n; i++) {
            y = p[y];
        }
        for (int cur = y; ; cur = p[cur]) {
            cyc.push_back(cur);
            if (cur == y && cyc.size() > 1)  break;
        }
        for (auto b : cyc) ban[b] = 1;
    }

    for (int i = 0; i < n; i++) {
        if (used[i] && ban[i]) {
            cout << ":)"; return 0;
        }
    }
    cout << d[n - 1];
    return 0;
}