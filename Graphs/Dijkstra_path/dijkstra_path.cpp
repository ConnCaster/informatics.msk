#include <bits/stdc++.h>

using namespace std;
#define INF INT_MAX

signed main() {
    int n, from, to;
    cin >> n >> from >> to;
    from--;
    to--;
    vector<vector<int>> adjacency_matrix(n, vector<int>(n));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            cin >> adjacency_matrix[i][j];
            adjacency_matrix[i][j] = (adjacency_matrix[i][j] == -1) ? 0 : adjacency_matrix[i][j];
        }
    vector<int> visited(n, 0);
    vector<int> dist(n, INF);
    dist[from] = 0;
    vector<int> path_to(n, -1);

    int minimal_distance = 0, minimal_vortex;
    while(minimal_distance < INF) {
        minimal_distance = INF;
        minimal_vortex = -1;
        for (int j = 0; j < n; j++) {
            if (visited[j] == 0 && dist[j] < minimal_distance) {
                minimal_distance = dist[j];
                minimal_vortex = j;
            }
        }
        if(minimal_distance != INF) {
            visited[minimal_vortex] = 1;
            for (int j = 0; j < n; j++) {
                if (adjacency_matrix[minimal_vortex][j] != 0 && // есть ребро
                    dist[minimal_vortex] + adjacency_matrix[minimal_vortex][j] < dist[j]) {
                    dist[j] = dist[minimal_vortex] + adjacency_matrix[minimal_vortex][j];
                    path_to[j] = minimal_vortex;
                }
            }
        }
    }

//     cout << ((dist[to] != INF) ? dist[to] : -1); // Shortest distance to vortex

    if(dist[to] != INF) {
        int current_step = to;
        vector<int> answer;
        while (current_step != -1) {
            answer.push_back(current_step);
            current_step = path_to[current_step];
        }
        reverse(answer.begin(), answer.end());
        for (auto i: answer) cout << i + 1 << " ";
    } else {
        cout << -1;
    }
    return 0;
}