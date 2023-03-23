#include <bits/stdc++.h>

const int k = 16;

const int N = 1e5;

long long table[N][k + 1];

void build_sparse_table(std::vector<int>& arr, int n) {
    for (int i = 0; i < n; i++)
        table[i][0] = arr[i];
    for (int j = 1; j <= k; j++)
        for (int i = 0; i <= n - (1 << j); i++)
            table[i][j] = table[i][j - 1] + table[i + (1 << (j - 1))][j - 1];
}

long long query(int L, int R) {
    long long answer = 0;
    for (int j = k; j >= 0; j--) {
        if (L + (1 << j) - 1 <= R) {
            answer = answer + table[L][j];
            L += 1 << j;
        }
    }
    return answer;
}

int main() {
    int N;
    std::cin >> N;
    std::vector<int> v(N, 0);
    for (int i = 0; i < N; i++) {
        int x;
        std::cin >> x;
        if (x == 0) v[i] = 1;
        else v[i] = 0;
    }

    build_sparse_table(v, N);

    int count;
    std::cin >> count;
    for (int i = 0; i < count; ++i) {
        int r, l;
        std::cin >> l >> r;
        std::cout << query(l-1,r-1) << " ";
    }


    return 0;
}