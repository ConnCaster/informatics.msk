#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

/*
6 4
1 2 7
2 4 8
4 5 1
4 3 100
3 1

 115
*/


class Graph{
public:
    explicit Graph(int N)
    : N(N), gr(N, std::vector<int>(N, 0)), visited(N, 0), dist(N, INT_MAX), p(N, -1)
    {}

    void read_graph(int K){
        int start{}, stop{}, distance{};
        for (int i = 0; i < K; ++i) {
            std::cin >> start >> stop >> distance;
            gr[start-1][stop-1] = distance;
            gr[stop-1][start-1] = distance;
        }
    }

    void print() const {
        for (int i = 0; i < N; ++i) {
            for (int elem : gr[i])
                std::cout << elem<< "\t";
            std::cout << std::endl;
        }
    }

    std::vector<int> get_visited() const {
        return visited;
    }

    void Dijkstra(int st) {
        int index, u;
        dist[st] = 0;
        for (int count=0; count < N; count++)
        {
            uint min=INT_MAX;
            for (int i = 0; i < N; i++) {
                if (visited[i] == 0 && dist[i] <= min) {
                    min = dist[i];
                    index = i;
                }
            }
            u=index;
            visited[u]=true;
            for (int i = 0; i < N; i++)
                if (!visited[i] && gr[u][i] && dist[u] != INT_MAX && dist[u] + gr[u][i] < dist[i]){
                    dist[i]=dist[u]+gr[u][i];
                    p[i] = u;
                }
        }
        /*std::cout << "Стоимость пути из начальной вершины до остальных:\t\n";
        for (int i = 0; i < N; i++) {
            if (dist[i] != 10000000) std::cout << m << " > " << i + 1 << " = " << dist[i] << std::endl;
            else std::cout << m << " > " << i + 1 << " = " << "маршрут недоступен" << std::endl;
        }*/
    }

    void Dijkstra_new(int st) {
        dist[st] = 0;
        uint minimal_distance = 0, minimal_vortex;
        while(minimal_distance < INT_MAX) {
            minimal_distance = INT_MAX;
            minimal_vortex = -1;
            for (int j = 0; j < N; j++) {
                if (visited[j] == 0 && dist[j] < minimal_distance) {
                    minimal_distance = dist[j];
                    minimal_vortex = j;
                }
            }
            if(minimal_distance != INT_MAX) {
                visited[minimal_vortex] = 1;
                for (int j = 0; j < N; j++) {
                    if (gr[minimal_vortex][j] != 0 && // есть ребро
                        dist[minimal_vortex] + gr[minimal_vortex][j] < dist[j]) {
                        dist[j] = dist[minimal_vortex] + gr[minimal_vortex][j];
                        p[j] = minimal_vortex;
                    }
                }
            }
        }
    }

    void print_dist(int stop) {
        if(dist[stop] != INT_MAX) {
            uint current_step = stop;
            std::vector<uint> answer;
            uint distance_full = dist[stop];
            while (current_step != -1) {
                answer.push_back(current_step);
                current_step = p[current_step];
            }
            reverse(answer.begin(), answer.end());
            std::cout <<  distance_full;
        } else {
            std::cout << -1;
        }
    }

/*    void get_path(int start, int stop){
        std::vector<int> gr;
        if (p[stop-1] == -1)
            std::cout<<"No way\n";
        else{
            for (int u = stop-1 ; u != -1; u = p[u]){
                gr.push_back(u+1);
            }
            gr.push_back(start);
            std::reverse(gr.begin(),gr.end());
            for (int i : gr) {
                std::cout << i << " ";
            }
        }
    }*/

private:
    int N; // amount of solders
    std::vector<std::vector<int>> gr;
    std::vector<int> visited;
    std::vector<uint>dist;
    std::vector<uint> p;
};


int main() {
    int N{}, K{};
    std::cin >> N >> K;
    Graph gr{N};
    gr.read_graph(K);
//    gr.print();
    int start{}, stop{};
    std::cin >> start >> stop;
    gr.Dijkstra_new(start-1);
    gr.print_dist(stop-1);
//    std::cout << gr.get_distance(stop);
    return 0;
}