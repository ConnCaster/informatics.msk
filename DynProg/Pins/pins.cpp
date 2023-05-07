#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, elem;
    cin >> n;
    vector<int> coordinates;
    vector<int> summa;
    for(int i = 0; i < n; ++i){
        cin >> elem;
        coordinates.push_back(elem);
    }
    std::sort(coordinates.begin(), coordinates.end());
    if(n == 2){
        cout << coordinates[1] + coordinates[0];
        return 0;
    }

    summa.push_back(coordinates[1] - coordinates[0]);
    summa.push_back(coordinates[2] - coordinates[0]);
    for(int i = 2; i < coordinates.size() - 1; ++i)
        summa.push_back(min(summa[i - 1], summa[i - 2]) + abs(coordinates[i] - coordinates[i + 1]));

    cout << summa[summa.size() - 1];
    return 0;
}