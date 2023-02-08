#include<bits/stdc++.h>
using namespace std;

/*
3
1 1
1 2
10 1
1
2 1

 9.0
 */

struct Edge {
    int from;
    int to;
    int d;
};

bool operator<(const Edge &a, const Edge &b) {
    return a.d < b.d;
}

class DisjointSet {
public:
    explicit DisjointSet(int n)
    : parent(1 + n, -1)
    {}

    int findRoot(int x) {
        if (parent[x] < 0)
            return x;
        return parent[x] = findRoot(parent[x]);
    }

    bool Union(int x, int y) {
        int rx = findRoot(x);
        int ry = findRoot(y);

        if (rx == ry) {
            return false;
        }
        if (parent[rx] < parent[ry]) {
            parent[rx] += parent[ry];
            parent[ry] = rx;
        } else {
            parent[ry] += parent[rx];
            parent[rx] = ry;
        }
        return true;
    }

private:
    vector<int> parent;
};

class Graph{
public:
    explicit Graph(int V)
    : nV(V), x(1 + nV), y(1 + nV), ds(nV)
    {}

    void read_graph(){
        for (int i = 1; i <= nV; ++i) {
            std::cin >> x[i] >> y[i];
        }
    }

    void read_edges(int nE){
        for (int i = 0; i < nE; ++i) {
            int s, d;
            std::cin >> s >> d;
            ds.Union(s, d);
        }
        for (int i = 1; i <= nV; ++i) {
            for (int j = i+1; j <= nV; ++j) {
                int dx = x[i] - x[j];
                int dy = y[i] - y[j];
                edges.push_back(Edge{i, j, dx*dx + dy*dy});
            }
        }
        sort(edges.begin(), edges.end());
    }

    void boruvka() {
        double sum = 0;
        for (auto e: edges) {
            if (ds.Union(e.from, e.to))
                sum += std::sqrt(e.d);
        }
        cout << sum << endl;
    }

private:
    int nV;
    DisjointSet ds;
    vector<Edge> edges{};
    std::vector<int> x;
    std::vector<int> y;
};

int main() {
    int V, E;
    std::cin >> V;
    auto graph = Graph{V};
    graph.read_graph();
    std::cin >> E;
    graph.read_edges(E);
    graph.boruvka();
    return 0;
}