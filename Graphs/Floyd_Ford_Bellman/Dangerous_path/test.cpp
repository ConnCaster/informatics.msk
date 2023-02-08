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
            : N(N), M(M), gr(N, std::vector<int>(N, 0)),  danger(N, std::vector<float>(N, 0)), d(N, 0)
    {}

    void read_graph(){
        int s = 0, d = 0, v = 0;
        for (int i = 0; i < M; ++i) {
            std::cin >> s >> d >> v ;
            gr[s-1][d-1] = v;

        }
    }

    void print() const {
        for (int i = 0; i < M; ++i) {
            for (int elem : gr[i])
                std::cout << elem<< " ";
            std::cout << std::endl;
        }
    }

    void floyd(int src, int dst){
        src--;
        dst--;
        for (int k = 0; k < N; ++k) {
            float a = 1 - static_cast<float>(gr[src][dst]) / 100;
            float b = 1 - (1 - static_cast<float>(gr[src][k]) / 100) * (1 - static_cast<float>(gr[k][dst]) / 100);
            d.push_back(std::min(a, b));
        }
//        for( auto elem : d){
//            std::cout << elem << " ";
//        }
//        std::cout << std::endl;
    }

    auto getter() {
        auto it = std::remove(d.begin(), d.end(), 0);
        return std::min_element(d.begin(), d.end());
    }

private:
    int N, M;
    std::vector<std::vector<int>> gr;
    std::vector<std::vector<float>> danger;
    std::vector<float> d;
};

int main() {
    int N = 0, M = 0;
    std::cin >> N >> M;
    int s = 0, d = 0;
    std::cin >> s >> d;
    auto graph = Graph{N, M};
    graph.read_graph();
    graph.floyd(s, d);
    std::cout << *graph.getter();
    return 0;
}