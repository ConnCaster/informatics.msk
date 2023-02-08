#include <iostream>
#include <vector>
#include <algorithm>

/*
3 1
0 1 1
1 0 0
1 0 0

3
 */

class Graph{
public:
    explicit Graph(int N)
            : N(N), gr(N), visited(N, 0)
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


    void dfs (int v) {
        visited[v] = 1;
        for (int to : gr[v]) {
            if (visited[to] == 0){
                dfs (to);
            }
        }
        visited[v] = 2;
    }

    std::vector<int> get_visited() {
        return visited;
    }

private:
    int N;
    std::vector<std::vector<int>> gr;
    std::vector<int> visited;
};
int main() {
    int N = 0, source = 0;
    std::cin >> N >> source;
    auto graph = Graph{N};
    graph.read_graph();
    graph.dfs(source);
    auto res = graph.get_visited();
    std::cout << res.size();
    return 0;
}
