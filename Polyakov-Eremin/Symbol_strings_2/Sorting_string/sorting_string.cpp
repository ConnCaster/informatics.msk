#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N = 0;
    std::cin >> N;
    std::vector<std::string> v{};
    for (int i = 0; i < N; ++i) {
        int tmp;
        std::cin >> tmp;
        std::cin.ignore(2);
        std::string s;
        std::cin >> s;
        v.push_back(s);
    }
    std::sort(v.begin(), v.end(), [](std::string& l, std::string& r){
        return l < r;
    });
    for (int i = 0; i < N; ++i) {
        std::cout << i+1 << ". " << v[i] << std::endl;
    }
    return 0;
}