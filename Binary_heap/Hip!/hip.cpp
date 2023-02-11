#include <iostream>
#include <queue>

/*
 2
 0 10000
 1
 выходные данные
 10000
 */


using namespace std;

int main() {
    int n;
    cin >> n;
    priority_queue<int> heap;
    for (int i = 0; i < n; i++) {
        int command;
        cin >> command;
        if (command == 0) {
            int number;
            cin >> number;
            heap.push(number);
        } else if (command == 1) {
            int maxNumber = heap.top();
            heap.pop();
            cout << maxNumber << endl;
        }
    }
    return 0;
}