#include <iostream>
#include <deque>
#include <vector>
#include <iterator>
#include <algorithm>

struct Min {
    std::deque<int> _d;

    void push(int n) {
        while(!_d.empty() && _d.back() > n)
            _d.pop_back();
        _d.push_back(n);
    }

    int min() const {
        return _d.front();
    }

    void pop(int n) {
        if (!_d.empty() && _d.front() == n)
            _d.pop_front();
    }
};

int main() {
    Min m;
    int n, k;
    std::cin >> n >> k;

    typedef std::istream_iterator<int> in;
    std::vector<int> v(n);
    std::copy(in(std::cin), in(), v.begin());

    for (int i = 0; i < k; ++i)
        m.push(v[i]);

    std::cout << m.min() << '\n';
    for (int i = k; i < n; ++i) {
        m.push(v[i]);
        m.pop(v[i-k]);
        std::cout << m.min() << '\n';
    }

    return 0;
}