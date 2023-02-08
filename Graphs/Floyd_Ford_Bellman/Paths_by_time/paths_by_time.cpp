#include<iostream>
#include<math.h>

#define size 2023
int numOfPoints, srcPoint, dstPoint, numOfTrips, timeStart[ size],
timeEnd[size], nextHop[size], nextPoint[size], isRouteExist[size][size],
minTimeRoute[size][size], startPoint[size], currentPoint;


void initializeGraph() {
    std::cin >> numOfPoints >> srcPoint >> dstPoint >> numOfTrips;
    int i, stopPoint;
    for (i = 1; i <= numOfPoints; i++)
        nextHop[i] = 0;
    for (i = 1; i <= numOfTrips; i++) {
        std::cin >> startPoint[i] >> timeStart[i] >> stopPoint >> timeEnd[i];
        nextPoint[i] = nextHop[stopPoint];
        nextHop[stopPoint] = i;
    }
}
int calculateModifyFordBellman() {
    int i, j;
    int k;
    int fMax = fmax(numOfPoints, numOfTrips);
    for (i = 1; i <= numOfPoints; i++) isRouteExist[i][0] = 0;
    minTimeRoute[srcPoint][0] = 0;
    isRouteExist[srcPoint][0] = 1;
    for (i = 1; i <= fMax; i++) {
        for (j = 1; j <= numOfPoints; j++) {
            isRouteExist[j][i] = 0;
            if (isRouteExist[j][i - 1]) {
                isRouteExist[j][i] = 1;
                minTimeRoute[j][i] = minTimeRoute[j][i - 1];
            }
            for (k = nextHop[j]; k != 0; k = nextPoint[k]) {
                currentPoint = startPoint[k];
                if (isRouteExist[currentPoint][i - 1] && minTimeRoute[currentPoint][i - 1] <= timeStart[k] && (!isRouteExist[j][i] || timeEnd[k] < minTimeRoute[j][i]))
                    minTimeRoute[j][i] = timeEnd[k], isRouteExist[j][i] = 1;
            }
        }
    }
    return minTimeRoute[dstPoint][fMax];
}


int main () {
    initializeGraph();
    std::cout << calculateModifyFordBellman() << std::endl;
    return 0;
}