#include <iostream>
#include <vector>
#include <algorithm>

/*
4
0 5 9 100
100 0 2 8
100 100 0 7
4 100 100 0


 0 5 7 13
 12 0 2 8
 1 6 0 7
 4 9 11 0
 */

class Graph{
public:
    explicit Graph(int N)
    : N(N), gr(N)
    {}

    void read_graph(){
        int v = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                std::cin >> v;
                gr[i].push_back(v);
            }
        }
    }

    void print() const {
        for (int i = 0; i < N; ++i) {
            for (int elem : gr[i])
                std::cout << elem<< " ";
            std::cout << std::endl;
        }
    }

    void ford_bellman(){
        for (int k = 0; k < N; ++k) {
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    gr[i][j] = std::min(gr[i][j], gr[i][k] + gr[k][j]);
                }
            }
        }
    }

private:
    int N;
    std::vector<std::vector<int>> gr;
};

int main() {
    int N = 0;
    std::cin >> N;
    auto graph = Graph{N};
    graph.read_graph();
    graph.ford_bellman();
    graph.print();
    return 0;
}
