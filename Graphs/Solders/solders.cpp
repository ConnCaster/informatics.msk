#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

/*
3 7
1 2
2 3
1 3
2 3
1 2
1 2
1 3

 YES
 1 2 3

4 5
1 2
2 3
3 4
1 4
4 1

 NO


6 6
2 3
3 1
4 0
4 1
5 2
5 0

 5 2 3 1 0 4
 */



#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

class Graph{
public:
    explicit Graph(int N, int M)
            : N(N), M(M), gr(N), visited(N, 0), parents(N, -1), topsort{}
    {}

    void read_graph(){
        int s{}, d{};
        for (int i = 0; i < M; ++i) {
            std::cin >> s >> d;
            if (s == d) continue;
            if (pairs.find(std::make_pair(s, d))!= pairs.end()) continue;
            else pairs.insert(std::make_pair(s, d));
            gr[s-1].push_back(d-1);
        }
    }

    void print() const {
        for (int i = 0; i < N; ++i) {
            std::cout << i  << ": ";
            for (int elem : gr[i])
                std::cout << elem  << " ";
            std::cout << std::endl;
        }
    }

    std::vector<int> get_visited() const {
        return visited;
    }

    std::vector<int> get_topsort() const {
        return topsort;
    }

    int dfs_find_loop (int v) {
        visited[v] = 1;
        for (int to : gr[v]) {
            if (visited[to] == 0){
                parents[to] = v;
                if (dfs_find_loop(to) == 1) return 1;
            }
            if (visited[to] == 1 && to != parents[v]) {
                // если вершина, в которую я могу пойти уже посещена и не является той,
                // из которой я сюда пришел, то мы нашли цикл
                return 1;
            }
        }
        visited[v] = 2;
        return 0;
    }

    void dfs (int v) {
        visited[v] = 1;
        for (int to : gr[v]) {
            if (visited[to] == 0){
                dfs(to);
            }
        }
        topsort.push_back(v);
    }

    void top_sort() {
        for (int i = 0; i < N; ++i)
            visited[i] = 0;
        for (int i = 0; i < N; ++i) {
            if (visited[i] == 0) dfs(i);
        }
    }

private:
    int N; // amount of solders
    int M; // amount of pairs
    std::vector<std::vector<int>> gr;
    std::vector<int> visited;
    std::set<std::pair<int, int>> pairs; // unique pairs of solders
    std::vector<int> parents;
    std::vector<int> topsort;
};


int main()
{

    int N{}, M{};
    std::cin >> N >> M;
    Graph gr{N, M};
    gr.read_graph();
//    gr.print();
    for(int i = 0; i < N; ++i){
        if(gr.get_visited()[i] == 0) {
            if (gr.dfs_find_loop(i) == 1) {
                std::cout << "No";
                return 0;
            }
        }
    }

    gr.top_sort();
    if (gr.get_topsort().empty()) {
        std::cout << "No" << std::endl;
    }
    std::cout << "Yes" << std::endl;
    for(int i = gr.get_topsort().size()-1; i>=0; --i)  // TODO: SIGABOURT
        std::cout << gr.get_topsort()[i] + 1 << " ";

    return 0;
}