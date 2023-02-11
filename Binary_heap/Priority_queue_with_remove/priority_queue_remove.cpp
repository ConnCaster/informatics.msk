#include <iostream>
#include <vector>

class PH{
public:
    explicit PH(int N):
    N(N)
    {}

    void push(int num) {
        size_t size = data.size();
        if (size == 0) {
            data.push_back(num);
            std::cout << 1 << std::endl;
        } else if (size == N){
            std::cout << -1 << std::endl;
        } else {
            data.push_back(num);
            int pos = data.size() - 1;
            int parent = (pos - 1) / 2;
            while (pos > 0 && data[parent] < data[pos]) {
                std::swap(data[pos], data[parent]);
                pos = parent;
                parent = (pos - 1) / 2;
            }
            std::cout << pos+1 << std::endl;
        }
    }

    int heapify(int i) {
        size_t size = data.size();
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if (l < size && data[l] > data[largest])
            largest = l;
        if (r < size && data[r] > data[largest])
            largest = r;

        if (largest != i) {
            std::swap(data[i], data[largest]);
            i = heapify(largest);
        }
        return i;
    }

    void top() {
        if (data.size() == 0) std::cout << -1 << std::endl;
        else {
            int tmp = data[0];
            std::swap(data[0], data[data.size() - 1]);
            data.pop_back();
            if (data.size() == 0) std::cout << 0 << " " << tmp << std::endl;
            else {
                std::cout << heapify(0) + 1 << " " << tmp << std::endl;
            }
        }
    }

    void remove(int pos) {
        size_t size = data.size();
        if (pos >= data.size()) {
            std::cout << -1 << std::endl;
            return;
        }
        std::cout << data[pos] << std::endl;
        std::swap(data[pos], data[size - 1]);
        data.pop_back();
        for (int j = size / 2; j >= 0; j--) {
            heapify(j);
        }
    }

    void print() {
        for (int elem : data) {
            std::cout << elem << " ";
        }
    }

private:
    int N;
    std::vector<int> data;
};

int main() {
    int N = 0, M = 0, cmd = 0;
    std::cin >> N >> M;
    PH ph{N};
    for (int i = 0; i < M; ++i) {
        std::cin >> cmd;
        if (cmd == 2) {
            int n;
            std::cin >> n;
            ph.push(n);
        } else if (cmd == 1){
            ph.top();
        } else {
            int pos = 0;
            std::cin >> pos;
            ph.remove(pos-1);
        }
    }
    ph.print();
}
/*
-1
1
2
3
2
-1
2 9
-1
4
9
9 4 1
 */