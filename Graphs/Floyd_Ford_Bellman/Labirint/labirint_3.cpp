#include<bits/stdc++.h>
using namespace std;
#define inf 1e10l
struct osnovn {
    int from, to, w;
};

int main() {
    int n, m, u, v, w;
    cin >> n >> m;
    vector<osnovn> gr;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        gr.push_back({--u, --v, -w});
    }
    vector<long long > d(n, 1e18 );
    d[0] = 0;
    int step = 0;
    for (; step <= n + 1; step++) {
        bool changed = false;
        for (auto& el : gr) {
            if (d[el.from] > -inf && d[el.to] > d[el.from] + el.w) {
                d[el.to] = d[el.from] + el.w;
                changed = true;
            }
        }
        if (!changed) break;
    }
    if (step == n + 1)
        cout << ":)" << endl;
    else if (d[n - 1] == 1e18)
        cout << ":(" << endl;
    else
        cout << -d[n - 1] << endl;
}