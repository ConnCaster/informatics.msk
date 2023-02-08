#include <iostream>
#include <vector>
/*
6
0 1 1 0 0 0
1 0 1 0 0 0
1 1 0 0 0 0
0 0 0 0 1 0
0 0 0 1 0 0
0 0 0 0 0 0

NO

3
0 1 0
1 0 1
0 1 0

 YES
 */

#include <iostream>
#include <vector>
#include <algorithm>

class Graph{
public:
    explicit Graph(int N)
            : N(N), gr(N), visited(N, 0), parents(N, 0)
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
                parents[to] = v;
                dfs (to);
            }
            if (visited[to] == 1 && to != parents[v]) {
                std::cout << "NO" << std::endl;  // цикл есть, а значит дерева нет
                exit(0);
            }
        }
        visited[v] = 2;
    }

    void svyaznost() const {
        for (auto node: visited) {
            if (node == 0) {
                std::cout << "NO" << std::endl;   // есть непосещенная вершина,
                                                  // а значит дерева нет
                exit(0);
            }
        }
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
    graph.dfs(0);
    graph.svyaznost();
    std::cout << "YES";
    return 0;
}
