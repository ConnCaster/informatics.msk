#include <iostream>
#include <vector>
/*
5
0 1 0 0 1
1 0 1 0 0
0 1 0 0 0
0 0 0 0 0
1 0 0 0 0
3 5

3
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

class Graph{
public:
    explicit Graph(int N)
            : N(N), gr(N), visited(N, 0), parents(N, -1)
    {}

    void read_graph(){
        for (int i = 0; i < N; ++i) {
            int v;
            for (int j = 0; j < N; ++j) {
                std::cin >> v;
                if (v == 1) gr[i].push_back(j);
            }
        }
    }

    void print() const {
        for (int i = 0; i < N; ++i) {
            std::cout << i << ": ";
            for (int elem : gr[i])
                std::cout << elem<< " ";
            std::cout << std::endl;
        }
    }


    std::vector<int> bfs(int s, int t) {
        std::vector<int> dist(N, N);
        dist[s] = 0;
        std::queue<int> q;
        q.push(s);

        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int to : gr[v]) {
                if (dist[to] > dist[v] + 1) {
                    parents[to] = v;
                    dist[to] = dist[v] + 1;
                    q.push(to);
                }
            }
        }
        if (dist[t] == N) {
            return {};
        }

        std::vector<int> path;
        while (t != -1) {
            path.push_back(t);
            t = parents[t];
        }

        reverse(path.begin(), path.end());
        return path;
    }

private:
    int N;
    std::vector<std::vector<int>> gr;
    std::vector<int> visited;
    std::vector<int> parents;
};


int main() {
    int N = 0;
    std::cin >> N;
    auto graph = Graph{N};
    graph.read_graph();
    int start, stop;
    std::cin >> start >> stop;
    auto path = graph.bfs(start-1, stop-1);
    if (path.empty()) std::cout << -1 << std::endl;
    else if(start == stop) std::cout << 0 << std::endl;
    else {
        std::cout << path.size()-1 << std::endl;
        for (const auto &elem : path) {
            std::cout << elem+1 << " ";
        }
    }
    return 0;
}