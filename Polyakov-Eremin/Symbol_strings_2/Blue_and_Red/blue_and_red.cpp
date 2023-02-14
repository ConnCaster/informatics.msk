#include <iostream>
#include <vector>

//BBBRBBRBRBRRRRRR

int main() {
    std::string s{};
    std::cin >> s;
    std::vector<int> idx_B{};
    std::vector<int> idx_R{};
    for (int i = 0; i < s.size(); ++i) {
        if (s.at(i) == 'R') idx_R.push_back(i);
        else idx_B.push_back(i);
    }
/*    int remove_pairs = 0;
    ulong min_size = std::min(idx_B.size(), idx_R.size());
    for (int i = 0; i < min_size; ++i) {
        if (idx_R[i] < idx_B[min_size - i - 1])
            remove_pairs++;
    }
    for (int i = 0; i < idx_B.size() - remove_pairs; ++i) {
        std::cout << "B";
    }
    for (int i = 0; i < idx_R.size() - remove_pairs; ++i) {
        std::cout << "R";
    }
    std::cout << std::endl << remove_pairs*2;*/
    int k = 0;
    while (idx_R[k] < idx_B[idx_B.size() - k - 1]) {
        k++;
    }
    for (int i = 0; i < idx_B.size() - k; ++i) {
        std::cout << "B";
    }
    for (int i = 0; i < idx_R.size() - k; ++i) {
        std::cout << "R";
    }
    std::cout << std::endl << k*2;
    return 0;
}