#include <iostream>
#include <vector>
#include <algorithm>

/*
2

 117

3

 -164
 */

#define INF 30000

class Graph{
public:
    explicit Graph(int N)
    : N(N), gr(N+1, INF)
    {
        gr[1] = 0;
    }

    void ford_bellman(){
        bool f;
        do{
            f = false;
            for (int i = 1; i <= N; ++i) {
                for (int j = i+1; j <= N; ++j) {
                    int k = (179*i + 719*j) % 1000 - 500;
                    if (gr[j] > gr[i] + k) {
                        f = true;
                        gr[j] = gr[i] + k;
                    }
                }
            }
        } while (f);
        std::cout << gr[N];
    }

private:
    int N;
    std::vector<int> gr;
};

int main() {
    int N = 0;
    std::cin >> N;
    auto graph = Graph{N};
    graph.ford_bellman();
    return 0;
}
