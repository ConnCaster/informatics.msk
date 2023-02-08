#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
vector<int> used;
vector<int> ans;

void dfs(int v){
    used[v]=1;
    for(auto u:g[v]){
        if(used[u]==1){
            cout <<"No";
            exit(0);
        }
        else if (!used[u]){
            dfs(u);
        }
    }
    used[v]=2;
    ans.push_back(v);
}

int main () {
    int n, m;
    cin >>n >>m;
    used.resize(n, 0);
    g.resize(n);
    for(int i=0, a, b; i<m; i++){
        cin >>a >>b;
        a--;
        b--;
        g[a].push_back(b);
    }
    for(int i=0; i<n; i++){
        if(!used[i]){
            dfs(i);
        }
    }
    cout << "Yes" <<'\n';
    reverse(ans.begin(), ans.end());
    for(auto &u:ans){
        cout <<u+1 <<" ";
    }
    return 0;
}