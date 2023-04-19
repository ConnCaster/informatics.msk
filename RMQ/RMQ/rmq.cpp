#include <cstdio>
#include <cmath>
#include <vector>
#include <climits>
#include <iostream>

using namespace std;

int main() {

    int N, K, maxSizeOfN = 100000;
    int SIZE_OF_GROUP = (int)ceil(sqrt(maxSizeOfN / 2));
    //определение оптимального размера группы для худшего случая
    // (использование последовательности с максимальным количеством элементов N = 10^5)
    std::cin >> N;

    int numberOfGroup = N / SIZE_OF_GROUP;
    vector<int> numbers(1+N);  // анализируемая последовательность
    vector<int> maxNumInGroup(1+numberOfGroup,INT_MIN); // максимальные элементы в каждой подгруппе,
    vector<int> indexOfMaxNumInGroup(1+numberOfGroup,0); // индексы соответствующих  элементов
    vector<int> maxElements(0); // тут будут храниться максимальные элементы на участках, задаваемых в запросе
    vector<int> indexesOfMaxElements(0); // а здесь их индексы


    for (int i = 1; i <= N; i++) {
        std::cin >> numbers[i];
        if (numbers[i] > maxNumInGroup[i / SIZE_OF_GROUP]) { //сравниваем с максимальным элементом в каждой подгруппе
            maxNumInGroup[i / SIZE_OF_GROUP] =  numbers[i];
            indexOfMaxNumInGroup[i / SIZE_OF_GROUP]= i;
        }
    }

    std::cin >> K;

    //выполнение запросов
    for (int i = 0; i < K; i++) {
        int l; //l и r границы отрезка из условий
        int r;

        std::cin >> l >> r;

        int maxNumberInSegment = INT_MIN;
        int indexOfMaxNumInSegment = 0;
        int indexOfGroupWithL = l / SIZE_OF_GROUP; //номер группы, в которой находится элемент с индексом l
        int indexOfGroupWithR = r / SIZE_OF_GROUP; //номер группы, в которой находится элемент с индексом r
        if (indexOfGroupWithL == indexOfGroupWithR) { //если они одной группе тупо берем максимум внутри нее
            for (int j = l; j <= r; j++) {
                if (numbers[j] > maxNumberInSegment) {
                    maxNumberInSegment = numbers[j];
                    indexOfMaxNumInSegment = j;
                }
            }
        } else { //иначе идем по всем группам
            for (int j = l; j < (indexOfGroupWithL + 1) * SIZE_OF_GROUP; j++) {
                // до индекса первого элемента в следующей группе после группы с элементом l
                if (numbers[j] > maxNumberInSegment) {
                    maxNumberInSegment = numbers[j];
                    indexOfMaxNumInSegment = j;
                }
            }
            for (int j = indexOfGroupWithL + 1; j < indexOfGroupWithR; j++) { // проходим по всем группам
                if (maxNumInGroup[j] > maxNumberInSegment) {
                    maxNumberInSegment = maxNumInGroup[j];
                    indexOfMaxNumInSegment = indexOfMaxNumInGroup[j];
                }
            }
            for (int j = indexOfGroupWithR * SIZE_OF_GROUP; j <= r; j++) {
                // проходим по группе с элементом  r (не дальше него самого)
                if (numbers[j] > maxNumberInSegment) {
                    maxNumberInSegment = numbers[j];
                    indexOfMaxNumInSegment = j;
                }
            }
        }
        maxElements.push_back(maxNumberInSegment);
        indexesOfMaxElements.push_back(indexOfMaxNumInSegment);
    }
    for (int i = 0; i < K; i++) {
        std::cout << maxElements[i] << " " << indexesOfMaxElements[i] << std::endl;
    }
    return 0;
}
