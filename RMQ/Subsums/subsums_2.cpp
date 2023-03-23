#include <bits/stdc++.h>

int main() {
    int N;
    std::cin >> N;
    std::vector<int> v(1 + N, 0);
    for (int i = 1; i <= N; i++) {
        std::cin >> v[i];
    }

    std::vector<long long> s(1 + N);
    s[0] = 0;
    for (int i = 1; i <= N; ++i) {
        s[i] = s[i - 1] + v[i];
    }

    int count;
    std::cin >> count;
    for (int i = 0; i < count; ++i) {
        int r, l;
        std::cin >> l >> r;
        std::cout << s[r] - s[l - 1] << " ";
    }


    return 0;
}

/*

using namespace std;

// Because 2^17 is larger than 10^5

const int k = 16;

// Maximum value of array

const int N = 1e5;

// k + 1 because we need to access
// table[r][k]

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
        std::cin >> v[i];
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
}*/
