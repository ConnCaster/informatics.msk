#include <iostream>
#include <vector>
#include <algorithm>

/*
3 3
1 3
1 2 20
1 3 50
2 3 20

0.36
 */

class Graph{
public:
    explicit Graph(int N, int M)
    : N(N), M(M), gr(N, std::vector<float>(N, 0))
    {}

    void read_graph(){
        int s = 0, d = 0, v = 0;
        for (int i = 0; i < M; ++i) {
                std::cin >> s >> d >> v ;
                gr[s-1][d-1] = 1 - static_cast<float>(v) / 100;
                gr[d-1][s-1] = 1 - static_cast<float>(v) / 100;
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
                    gr[i][j] = std::max(gr[i][j], gr[i][k] * gr[k][j]);
                }
            }
        }
    }

    auto get(int src, int dst) {
        return gr[src-1][dst-1];
    }

private:
    int N, M;
    std::vector<std::vector<float>> gr;
    std::vector<std::vector<float>> danger;
};

int main() {
    int N = 0, M = 0;
    std::cin >> N >> M;
    int s = 0, d = 0;
    std::cin >> s >> d;
    auto graph = Graph{N, M};
    graph.read_graph();
    graph.floyd();
    std::cout.precision(6);
    std::cout << std::fixed << 1 - graph.get(s, d);
    return 0;
}
