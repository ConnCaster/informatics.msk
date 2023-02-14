#include <iostream>
#include <vector>
//BBBRBBRBRBRRRRRR

int main() {
    std::string s{"hello"};
    std::cin >> s;
    std::vector<int> idx_B{};
    std::vector<int> idx_R{};
    for (int i = 0; i < s.size(); ++i) {
        if (s.at(i) == 'R') idx_R.push_back(i);
        else idx_B.push_back(i);
    }
    int k = 0;
    while (idx_R[k] < idx_B[idx_B.size() - 1 - k]) {
        k++;
    }
    for (int i = 0; i < idx_B.size() - k; ++i) {
        std::cout << "B";
    }
    for (int i = 0; i < idx_R.size() - k; ++i) {
        std::cout << "R";
    }
    std::cout << std::endl << k * 2;

    return 0;
}