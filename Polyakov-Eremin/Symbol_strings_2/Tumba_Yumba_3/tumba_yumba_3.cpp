#include <iostream>
#include <algorithm>

bool is_OK(const std::string& s) {
    for (int i = 0; i < s.size()-1; ++i) {
        if (s[i] == s[i+1]) return true;
    }
    return false;
}

int word_generator(std::string A, std::string &w, int N) {
    static int count = 0;
    if (N == w.size()) {
        if (is_OK(w)) {
            std::cout << w << std::endl;
            count++;
        }
        return count;
    }
    for (int i = 0; i < A.size(); i++) {
        w[N] = A[i];
        word_generator(A, w, N + 1);
    }
    return count;
}

int main() {
    std::string alph{};
    std::cin >> alph;
    int K = 0;
    std::cin >> K;
    std::string word(K, ' ');
    int res = word_generator(alph, word, 0);
    std::cout << res;
    return 0;
}