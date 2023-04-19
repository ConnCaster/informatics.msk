#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a - 1].push_back({b - 1, c});
    }
    vector<int> d(n, -1);
    d[0] = 0;
    queue<int> q;
    q.push(0);
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (auto to : g[v])
        {
            if (d[to.first] == -1 || d[to.first] < d[v] + to.second)
            {
                d[to.first] = d[v] + to.second;
                q.push(to.first);
                if (to.first == n - 1)
                {
                    cout << ":)";
                    return 0;
                }
            }
        }
    }
    if (d[n - 1] == -
            1)
        cout << ":(";
    else
        cout << d
        [n - 1];
    return 0;
}