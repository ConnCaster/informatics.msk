#include <iostream>
#include <vector>
#include <algorithm>

/*
3
0 7 3
7 0 10
2 215 0

10
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

    void floyd(){
        for (int k = 0; k < N; ++k) {
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    gr[i][j] = std::min(gr[i][j], gr[i][k] + gr[k][j]);
                }
            }
        }
    }

    int max(){
        int max = gr[0][0];
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                max = std::max(max, gr[i][j]);
            }
        }
        return max;
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
    graph.floyd();
//    graph.print();
    std::cout << graph.max();
    return 0;
}
