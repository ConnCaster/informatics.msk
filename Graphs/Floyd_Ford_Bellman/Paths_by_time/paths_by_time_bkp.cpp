#include <iostream>
#include <vector>
#include <algorithm>

/*
1
1 1
3
1 3 1 -5
1 -5 1 -3
1 -4 1 -10

 -10

2
1 1
2
1 1 2 10
1 10 1 9

 0

5
1 2
6
1 0 3 10
4 2 2 -10
4 14 2 -7
3 10 2 10
2 0 4 2
3 10 4 12

 -10
 */

class Graph{
public:
    explicit Graph(int N, int src, int dst, int num_trips)
    : N(N),
    source(src),
    dest(dst),
    num_trips(num_trips),
    startPoints(N, 0),
    endPoints(N, 0),
    startTime(N, 0),
    endTime(N, 0),
    minRouteTime(N, 1000000000)
    {
        minRouteTime[source-1] = 0;
    }

    void read_graph(){
        int src, dst, stime, dtime = 0;
        for (int i = 0; i < num_trips; ++i) {
            for (int j = 0; j < N; ++j) {
                std::cin >> src >> stime >> dst >> dtime;
                startPoints[i] = src;
                startTime[i] = stime;
                endPoints[i] = dst;
                endTime[i] = dtime;
            }
        }
    }

    void relaxBin(int i, int j, int stime, int dtime) {
        if (minRouteTime[i] <= stime && dtime < minRouteTime[j]) {
            minRouteTime[j] = dtime;
        }
    }

    int ford_bellman(){
        for (int i = 0; i < std::max(N, num_trips); ++i) {
            for (int j = 0; j < num_trips; ++j) {
                relaxBin(startPoints[j] - 1, endPoints[j] - 1, startTime[j], endTime[j]);
            }
        }
        return minRouteTime[dest-1];
    }

private:
    int N, source, dest, num_trips;
    std::vector<int> startPoints;
    std::vector<int> endPoints;
    std::vector<int> startTime;
    std::vector<int> endTime;
    std::vector<int> minRouteTime;
};

int main() {
    int N = 0;
    std::cin >> N;
    int src = 0, dst = 0;
    std::cin >> src >> dst;
    int num_trips = 0;
    std::cin >> num_trips;
    auto graph = Graph{N, src, dst, num_trips};
    graph.read_graph();
    std::cout << graph.ford_bellman();
    return 0;
}
