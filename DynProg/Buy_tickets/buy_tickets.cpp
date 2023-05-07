#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



int main() {
    int n, k;
    cin >> n;
    vector <int> d(n + 1);
    int a[n], b[n], c[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
        cin >> b[i];
        cin >> c[i];
    }
    d[0] = 0;
    d[1] = a[0];
    d[2] = min(a[0] + a[1], b[0]);
    for (int i = 3; i <= n; i++){
        k = min(d[i-1] + a[i - 1], d[i-2] + b[i-2]);
        d[i] = min(k, d[i-3] + c[i-3]);
    }
    cout << d[n];
    return 0;
}