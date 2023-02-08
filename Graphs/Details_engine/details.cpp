#include <iostream>
#include <vector>

using namespace std;

/*

3
100 200 300
1 2
0
2 2 1

4
2 3 4 5
2 3 2
1 3
0
2 1 3


2
2 3
1 2
0
 */

class Graph{
private:
    int len;
//    bool cycle;
    vector<vector<int>> gr;
    vector<int> visited;
    vector<int> topsort_arr;
    vector<int> times;
public:
    explicit Graph(int n)
            :len(n){   //cycle(false){
        gr.resize(len);
        visited.resize(len, 0);
    }

    void read(){
        int time;
        for (int  i = 0; i < len; i++){
            cin >> time;
            times.push_back(time);
        }
        for (int i = 0; i < len; i++){
            int tmp;
            cin >> tmp;
            for (int j = 0; j < tmp; j++){
                int node;
                cin >> node;
                gr[i].push_back(node - 1);
            }
        }
    }

    void topsort(){
        dfs(0);
        long long int sum = 0;
        for (int i : topsort_arr){
            sum += times[i];
        }
        cout << sum << " " << topsort_arr.size() << endl;
        for (int i = 0; i <= topsort_arr.size() - 1; ++i){
            cout << topsort_arr[i]+1  << " ";
        }
    }

    void dfs (int v) {
        visited[v] = 1;
        for (int to : gr[v]) {
            if (visited[to] == 0){
                dfs(to);
            }
        }
        topsort_arr.push_back(v);
    }

/*    void dfs(int node){
        visited[node] = 1;
        for (int Node : gr[node]){
            if (visited[Node] == 1) cycle = true;
            else if (visited[Node] == 0){
                dfs(Node);
            }
        }
        topsort_arr.push_back(node);
    }*/

};

int main(){
    int n;
    cin >> n;
    Graph gr{n};
    gr.read();
    gr.topsort();

    return 0;
}

