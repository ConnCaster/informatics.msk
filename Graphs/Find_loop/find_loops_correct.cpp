#include <iostream>
#include <vector>
using namespace std;
int a;
vector<int> stack;
bool dfs(int v,int pred , vector<vector<int>> &graph, vector<char> &color){
    stack.push_back(v);
    color[v]=1;
    for (int u: graph[v]){
        if (u == pred){
            continue;
        }
        if (color[u] == 1){
            a = u;
            return true;
        }
        if (color[u]==0){
            bool cycle_found = dfs(u , v, graph, color);
            if (cycle_found){
                return true;
            }
        }
    }
    color[v]=2;
    stack.pop_back();
    return false;
}

int main(){
    int n;
    cin >> n;
    int pred = -1;
    vector<vector<int>> graph(n);
    for (int i=0; i<n ; i++){
        for (int j=0; j<n ; j++){
            int t;
            cin >> t;
            if (t==1){
                graph[i].push_back(j);

            }
        }
    }
    vector<char> color(n);
    bool cycle_found = false;
    for (int i = 0 ; i < n; i++){
        if (color[i]==0){
            if (dfs(i ,pred, graph , color)){
                cycle_found = true;
                break;
            }
        }
    }
    if (!cycle_found){
        cout << "NO" << '\n';
    }
    else{
        cout << "YES" << '\n';
        int f = 0, dr=0;
        for(auto x: stack){
            if (x==a){
                f = 1;
            }
            if(f==1){
                dr++;
            }
        }
        cout <<  dr << "\n";
        int l = 0;
        for(auto x: stack){
            if (x==a){
                l = 1;
            }
            if(l==1){
                cout << x + 1 << " ";
            }
        }
    }
}