#include<bits/stdc++.h>
using namespace std;

/*
3 3
1 2 1
2 3 2
3 1 3

 3
 */

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
    explicit DisjointSet(int n)
    : parent(n), rank(n, 0)
    {
        std::iota(parent.begin(), parent.end(),0);
    }

    int findRoot(int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = findRoot(parent[x]);
    }

    void Union(int x, int y) {
        int rx = findRoot(x);
        int ry = findRoot(y);

        if (rx == ry) {
            return;
        }
        if (rank[rx] < rank[ry]) {
            parent[rx] = ry;
        } else {
            parent[ry] = rx;
            if (rank[rx] == rank[ry]) {
                ++rank[rx];
            }
        }
    }

private:
    vector<int> parent;
    vector<int> rank;
};

class Graph{
public:
    explicit Graph(int V, int E)
    : nE(E), nV(V)
    {}

    void read_graph(){
        for (int i = 0; i < nE; ++i) {
            int s, d, w;
            std::cin >> s >> d >> w;
            edges.push_back({s-1,d-1,w});
        }
        sort(edges.begin(), edges.end());
    }

    void boruvka() {
        DisjointSet ds(nV);
        int result = 0;
        for (int i = 0; i < nE; ++i) {
            int from = edges[i].from;
            int to = edges[i].to;
            if (ds.findRoot(from) != ds.findRoot(to)) {
                ds.Union(from, to);
                result += edges[i].weight;
            }
        }
        cout << result << endl;
    }

private:
    int nE;
    int nV;
    vector<Edge> edges;
};

int main() {
    int V, E;
    std::cin >> V >> E;
    auto graph = Graph{V, E};
    graph.read_graph();
    graph.boruvka();
    return 0;
}