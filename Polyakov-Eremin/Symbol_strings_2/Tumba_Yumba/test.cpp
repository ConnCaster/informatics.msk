#include <iostream>

bool is_OK(const std::string& s) {
    for (int i = 0; i < s.size()-1; ++i) {
        if (s[i] == s[i+1]) return true;
    }
    return false;
}


void word_generator(std::string alph, std::string& word, int K, int& counter){
    if (K == word.size()){
        if (is_OK(word)) {
            std::cout << word << std::endl;
            counter++;
        }
        return;
    }
    for (int i = 0; i < alph.size(); ++i) {
        word.at(K) = alph.at(i);
        word_generator(alph, word, K+1, counter);
    }
    return;
}

int main(){
    std::string alph{};
    std::cin >> alph;
    int K = 0;
    std::cin >> K;
    std::string word(K, ' ');
    int counter = 0;
    word_generator(alph, word, 0, counter);
    std::cout << counter;
    return 0;
}