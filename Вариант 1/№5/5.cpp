#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> bfs(int n, int start, vector<vector<int>>graph, vector<bool>& visited) //поиск в ширину
{
    queue<int> Q;
    vector<int> rast(n, -1);
    rast[0] = 0;
    Q.push(start);
    visited[start] = true;
    while (!Q.empty()) {
        int node = Q.front();
        Q.pop();
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                Q.push(neighbor);
                rast[neighbor] = rast[node] + 1;
            }
        }
    }

    return rast;
}

int main() {

    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<bool> visited(n);

    vector<int> rast = bfs(n, 0, graph, visited);

    vector<int> x;
    for (int i = 0; i < n; i++) {
        if (visited[i] == false) {
            x.push_back(i);
        }
    }

    if (x.size() != 0) {
        cout << "NO" << endl;
        for (int i = 0; i < x.size(); i++) {
            cout << x[i] << " ";
        }
    }

    else {
        cout << "YES" << endl;
        int MAX = 0;
        for (int i = 0; i < n; i++) {
            if (MAX < rast[i]) {
                MAX = rast[i];
            }
        }
        cout << MAX;
    }

	return 0;
}
