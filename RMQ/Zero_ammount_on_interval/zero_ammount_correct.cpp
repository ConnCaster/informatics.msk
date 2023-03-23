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
        if (v[i] == 0) s[i] = s[i - 1] + 1;
        else s[i] = s[i-1];
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