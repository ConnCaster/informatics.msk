#include <iostream>
#include <vector>
/*
3
0 1 1
1 0 1
1 1 0

 YES
 3
 3 2 1

4
0 0 1 0
0 0 0 1
1 0 0 0
0 1 0 0

 NO
 */

#include <iostream>
#include <vector>
#include <queue>
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
                // если вершина, в которую я могу пойти уже посещена и не является той,
                // из которой я сюда пришел, то мы нашли цикл
               std::cout << "YES" << std::endl;
               std::vector<int> path{v + 1};
               while(v != 0) {
                   v = parents[v];
                   path.push_back(v+1);
               }
               std::cout << path.size() << std::endl;
                for (auto elem: path) {
                    std::cout << elem << " ";
                }
               exit(0);
            }
        }
        visited[v] = 2;
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
    std::cout << "NO";
    return 0;
}
