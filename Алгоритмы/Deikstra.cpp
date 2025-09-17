#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int INF = 2e9;

struct ROAD {
    int v;
    int t;
    int p;
};

int Deiksrta(int start, vector<vector<ROAD>> &graph, int finish, int p) {
    vector<int> rast(graph.size(), INF);
    rast[start] = 0;
    
    set <pair<int, int>> Q;
    Q.insert({ 0, start });
    
    while (!Q.empty()) {
        int u = Q.begin()->second;
        if (u == finish) {
            return rast[finish];
        }
        Q.erase(Q.begin());

        for (auto road : graph[u]) {
            if (road.p >= p) {
                if (rast[u] + road.t < rast[road.v]) {
                    Q.erase({ rast[road.v], road.v });
                    rast[road.v] = rast[u] + road.t;
                    Q.insert({ rast[road.v], road.v });
                }
            }
        }
    }

    return -1;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<ROAD>> graph(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        int t, p;
        cin >> t >> p;

        ROAD road;
        road.v = v;
        road.p = p;
        road.t = t;
        graph[u].push_back(road);
        road.v = u;
        graph[v].push_back(road);
    }
    
    int ans = Deiksrta(0, graph, n-1, 0);
    cout << ans << endl;
 return 0;   
}
