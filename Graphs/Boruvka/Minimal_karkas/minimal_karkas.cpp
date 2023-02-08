#include<bits/stdc++.h>
using namespace std;

class Graph{
public:
    explicit Graph(int V, int E)
    : E(E), V(V)
    {}

    void read_graph(){
        for (int i = 0; i < E; ++i) {
            int s, d, w;
            std::cin >> s >> d >> w;
            gr.push_back({s,d,w});
        }
    }

    void boruvka() {
        for (int i = 0; i < V; i++) {
            trees.emplace_back(0,i);
        }
        int TotalTrees = V;
        int MST_total_weight = 0;
        while (TotalTrees > 1) {
            //A vector is created to store smallest edge
            //of each tree. And initialised to -1
            vector<int> smallest_edge(V,-1);
            // Traverse through all edges and update
            // smallest_edge of every tree
            for (int i=0; i<E; i++) {
                // Find trees of vertices(s-d) of current edge
                int setA = get_root(gr[i][0]);
                int setB = get_root(gr[i][1]);
                // If two vertices of current edge belong to
                //same tree -->continue
                if (setA == setB)
                    continue;
                else {
                    if (smallest_edge[setA] == -1 ||
                        gr[smallest_edge[setA]][2] > gr[i][2])
                        smallest_edge[setA] = i;
                    if (smallest_edge[setB] == -1 ||
                        gr[smallest_edge[setB]][2] > gr[i][2])
                        smallest_edge[setB] = i;
                }
            }
            for (int i=0; i<V; i++) {
                //if smallest_edge for current set exists
                if (smallest_edge[i] != -1) {
                    int setA= get_root(gr[smallest_edge[i]][0]);
                    int setB= get_root(gr[smallest_edge[i]][1]);
                    //belong to same tree
                    if (setA == setB)
                        continue;
                    MST_total_weight += gr[smallest_edge[i]][2];
                    merge(setA, setB);
                    TotalTrees--;
                }
            }
        }
        std::cout << MST_total_weight;
    }

private:
    int get_root(int i) {
        // second = parent of tree
        if (trees[i].second != i)
            trees[i].second = get_root(trees[i].second);
        return trees[i].second;
    }

    void merge(int a, int b) {
        int rootA = get_root(a);
        int rootB = get_root(b);
        if (trees[rootA].first < trees[rootB].first)
            trees[rootA].second = rootB;
        else if (trees[rootA].first > trees[rootB].first)
            trees[rootB].second = rootA;
        else {
            trees[rootB].second = rootA;
            trees[rootA].first++;
        }
    }

private:
    int E;
    int V;
    std::vector<std::vector<int>> gr{};
    vector<pair<int,int>>trees{};
};

int main() {
    int V, E;
    std::cin >> V >> E;
    auto graph = Graph{V, E};
    graph.read_graph();
    graph.boruvka();
    return 0;
}