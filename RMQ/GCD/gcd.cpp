#include <iostream>
#include <vector>

int GCD(int a, int b) {
    while (b != 0) {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> table(1, std::vector<int>(1 + n));
    for (int i = 1; i <= n; ++i) {
        std::cin >> table[0][i];
    }
    for (int len = 1; len * 2 <= n; len *= 2) {
        table.push_back(table.back());
        for (int i = 1; i + len <= n; ++i) {
            table.back()[i] = GCD(table.back()[i], table.back()[i + len]);
        }
    }

    std::vector<int> log2(1 + n, 0);
    // 0 1 2 3 4 5 6 7 8
    // 0 0 1 1 2 2 2 2 3
    for (int i = 2; i <= n; ++i) {
        log2[i] = log2[i/2] + 1;
    }

    int queries;
    std::cin >> queries;
    for (int i = 0; i < queries; ++i) {
        int l, r;
        std::cin >> l >> r;
        int level = log2[r - l + 1]; // длина отрезка определяет уровень в таблице
        std::cout << GCD(table[level][l], table[level][r - (1 << level) + 1]) << " ";
    }
    return 0;
}
// 2 2 2 1 5