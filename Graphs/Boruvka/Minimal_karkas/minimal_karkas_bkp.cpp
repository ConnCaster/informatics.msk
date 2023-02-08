#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int from;
    int to;
    int weight;
};

bool operator<(const Edge &a, const Edge &b) {
    return a.weight < b.weight;
}

class DisjointSet {
public:
    explicit DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int findRoot(int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = Find(parent[x]);
    }

    void Union(int x, int y) {
        x = Find(x);
        y = Find(y);

        if (x == y) {
            return;
        }
        if (rank[x] < rank[y]) {
            parent[x] = y;
        } else {
            parent[y] = x;
            if (rank[x] == rank[y]) {
                ++rank[x];
            }
        }
    }

private:
    vector<int> parent;
    vector<int> rank;
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<Edge> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].from >> edges[i].to >> edges[i].weight;
        --edges[i].from;
        --edges[i].to;
    }
    sort(edges.begin(), edges.end());
    DisjointSet ds(n);
    int result = 0;
    for (int i = 0; i < m; ++i) {
        int from = edges[i].
                from;
        int to = edges[i].to;
        if (ds.Find(from) != ds.Find(to)) {
            ds.Union(from, to);
            result += edges[i].weight;
        }
    }
    cout << result << endl;
    return 0;
}