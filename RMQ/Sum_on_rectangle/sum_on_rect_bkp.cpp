#include <bits/stdc++.h>


const int K = 19;
const int NN = 1e6;

//long long table[NN][K + 1];

void build_sparse_table(std::vector<int>& arr, int n, std::vector<std::vector<int>>& table) {
    for (int i = 0; i < n; i++)
        table[i][0] = arr[i];
    for (int j = 1; j <= K; j++)
        for (int i = 0; i <= n - (1 << j); i++)
            table[i][j] = table[i][j - 1] + table[i + (1 << (j - 1))][j - 1];
}

long long query(int L, int R, std::vector<std::vector<int>>& table) {
    long long answer = 0;
    for (int j = K; j >= 0; j--) {
        if (L + (1 << j) - 1 <= R) {
            answer = answer + table[L][j];
            L += 1 << j;
        }
    }
    return answer;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    int M, N, count;
    std::cin >> N >> M >> count;
    std::vector<std::vector<int>> mas(N, std::vector<int>(M, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
//            scanf("%d", &mas[i][j]);
            std::cin >> mas[i][j];
        }
    }
    for (int i = 0; i < count; ++i) {
        std::vector<std::vector<int>> table(N * M, std::vector<int>(K+1, 0));
        int x1, x2, y1, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        std::vector<int> v{};
        for (int t = y1; t <= y2; ++t) {
            for (int l = x1; l <= x2; ++l) {
                v.push_back(mas[l-1][t-1]);
            }
        }
        int size = v.size();
        build_sparse_table(v, size, table);
        std::cout << query(0, size-1, table) << std::endl;
    }
    return 0;
}