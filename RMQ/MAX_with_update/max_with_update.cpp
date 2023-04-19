#include <stdio.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <climits>


using namespace std;


int main() {
    int N;
    int K;
    const int maxSizeOfN = 100000;
    const int SIZE_OF_GROUP = (int) ceil(sqrt(maxSizeOfN / 2));
    std::cin >> N;

    int numberOfGroup;
    numberOfGroup = N / SIZE_OF_GROUP;
    vector<int> numbers(1 + N);
    vector<int> maxNumInGroup(1 + numberOfGroup, INT_MIN);
    vector<int> indexOfMaxNumInGroup(1 + numberOfGroup, 0);


    for (int i = 1; i <= N; i = i + 1) {
        std::cin >> numbers[i];
        maxNumInGroup[i / SIZE_OF_GROUP] = max(maxNumInGroup[i / SIZE_OF_GROUP], numbers[i]);
    }
    std::cin >> K;
    for (int i = 0; i < K; i = i + 1) {
        char typeOfQuery;
        std::cin >> typeOfQuery;
        if (typeOfQuery == 'm') {
            int l, r;
            std::cin >> l >> r;
            int indexOfGroupWithL = l / SIZE_OF_GROUP;
            int indexOfGroupWithR = r / SIZE_OF_GROUP;
            int maxNumberInSegment = INT_MIN;
            if (indexOfGroupWithL == indexOfGroupWithR) {
                for (int j = l; j <= r; j = j + 1) {
                    maxNumberInSegment = max(maxNumberInSegment, numbers[j]);
                }
            } else {
                for (int j = l; j < (indexOfGroupWithL + 1) * SIZE_OF_GROUP; j = j + 1) {
                    maxNumberInSegment = max(maxNumberInSegment, numbers[j]);

                }
                for (int j = indexOfGroupWithL + 1; j < indexOfGroupWithR; j = j + 1) {
                    maxNumberInSegment = max(maxNumberInSegment, maxNumInGroup[j]);
                }
                for (int j = indexOfGroupWithR * SIZE_OF_GROUP; j <= r; j = j + 1) {
                    maxNumberInSegment = max(maxNumberInSegment, numbers[j]);
                }

            }
            std::cout << maxNumberInSegment << " ";
        } else if (typeOfQuery == 'a') {
            int posL;
            int posR;
            int value;
            std::cin >> posL >> posR >> value;
            for (int pos = posL; pos <= posR; pos = pos + 1) {
                numbers[pos] += value;
                int numOfGroup;
                numOfGroup = pos / SIZE_OF_GROUP;
                maxNumInGroup[numOfGroup] = max(maxNumInGroup[numOfGroup], numbers[pos]);
            }
        }
    }
    return 0;
}