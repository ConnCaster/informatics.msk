#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    vector<int> f(n+1, 0);
    f[1] = a[1];
    for (int i = 2; i <= n; i++)
        f[i] = min(f[i-1], f[i-2]) + a[i];

    cout << f[n] << endl;
    return 0;
}