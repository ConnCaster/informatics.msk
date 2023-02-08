#include <iostream>
#include <vector>
#include <algorithm>

/*
4
1 1 0 0
0 1 1 0
1 0 1 0
0 0 1 1

1 1 1 0
1 1 1 0
1 1 1 0
1 1 1 1
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

    void trans_closure(){
        for (int k = 0; k < N; ++k) {
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    if (gr[i][k] != 0 && gr[k][j] != 0)
                        gr[i][j] = 1;
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
    graph.trans_closure();
    graph.print();
    return 0;
}
