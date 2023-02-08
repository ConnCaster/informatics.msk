#include<bits/stdc++.h>
using namespace std;

/*
5 8
1 3 75
3 4 51
2 4 19
3 2 95
2 5 42
5 4 31
1 2 9
3 5 66

 110 121
 */

const int USUAL = 1;
const int CHOSEN = 2;
const int FORBIDDEN = 3;

struct Edge {
    int from;
    int to;
    int weigth;
    int kind;
};

bool operator<(const Edge &a, const Edge &b) {
    return a.weigth < b.weigth;
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

    void reassign_parents(int value) {
        std::fill(parent.begin()+1, parent.end(), value);
    }

private:
    vector<int> parent;
};

class Graph{
public:
    explicit Graph(int V, int E)
    : nV(V), nE(E), ds(nV)
    {}

    void read_graph(){
        for (int i = 0; i <= nE; ++i) {
            int s, d, w;
            std::cin >> s >> d >> w;
            edges.push_back(Edge{s, d, w, USUAL});
        }
        sort(edges.begin(), edges.end());
    }

    void boruvka() {
        int min1 = 0;
        for (auto &e: edges) {
            if (ds.Union(e.from, e.to)) {
                min1 += e.weigth;
                e.kind = CHOSEN;
            }
        }
        int min2 = INT_MAX;
        for (auto &ce: edges) {
            if (ce.kind == CHOSEN) {
                ce.kind = FORBIDDEN;
                ds.reassign_parents(-1);
                int nEdges = 0;
                int sum = 0;
                for (auto &e: edges) {
                    if (e.kind != FORBIDDEN && ds.Union(e.from, e.to)) {
                        sum += e.weigth;
                        nEdges++;
                    }
                }
                if (nEdges == nV-1)
                    min2 = std::min(min2, sum);
                ce.kind = CHOSEN;
            }
        }
        cout << min1 << " " << min2 << endl;
    }

private:
    int nV;
    int nE;
    DisjointSet ds;
    vector<Edge> edges{};
    std::vector<int> x;
    std::vector<int> y;
};

int main() {
    int V, E;
    std::cin >> V >> E;
    auto graph = Graph{V, E};
    graph.read_graph();
    graph.boruvka();
    return 0;
}