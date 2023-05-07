#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<unsigned long long int>>w{};
    for (int i = 0; i < n; ++i) {
        vector<unsigned long long int> v(m, 1);
        w.push_back(v);
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++) {
            if(i==0 || j==0){
                w[i][j]=1;
            }else{
                w[i][j]=w[i-1][j]+w[i][j-1];
            }
        }
    }

    cout << w[n-1][m-1];
    return 0;
}