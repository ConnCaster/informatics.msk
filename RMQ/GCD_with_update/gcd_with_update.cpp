#include <iostream>
#include <vector>
#include <cmath>

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
    std::vector<int> a(n);
    int GROUP_SIZE = (int)ceil(sqrt(100000 / 2)); // 224
    std::vector<int> groups(1 + (n-1)/GROUP_SIZE, 0);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        int group = i / GROUP_SIZE;
        groups[group] = GCD(a[i], groups[group]);
    }

    int queries;
    std::cin >> queries;
    for (int i = 0; i < queries; ++i) {
        char cmd;
        std::cin >> cmd;
        if (cmd == 'u') {
            int pos, value;
            std::cin >> pos >> value;
            pos--;
            a[pos] = value;
            int group = pos / GROUP_SIZE;
            int afterCurrGroup = std::min(n, (group + 1) * GROUP_SIZE);
            int gcd = 0;
            for (int j = group * GROUP_SIZE; j < afterCurrGroup; ++j) {
                gcd = GCD(a[j], gcd);
            }
            groups[group] = gcd;
        } else if (cmd == 's') {
            int l, r;
            std::cin >> l >> r;
            l--;
            r--;
            int leftGroup = l / GROUP_SIZE;
            int rightGroup = r / GROUP_SIZE;
            int answer = 0;
            if (leftGroup == rightGroup) {
                for (int j = l; j <= r; ++j) {
                    answer = GCD(a[j], answer);
                }
            } else {
                int afterLeftGroup = (leftGroup+1) * GROUP_SIZE;
                for (int j = l; j < afterLeftGroup; ++j) {
                    answer = GCD(a[j], answer);
                }
                for (int j = leftGroup + 1; j < rightGroup; ++j) {
                    answer = GCD(groups[j], answer);
                }
                for (int j = rightGroup*GROUP_SIZE; j <= r; ++j) {
                    answer = GCD(a[j], answer);
                }
            }
            std::cout << answer << " ";
        }
    }
    return 0;
}