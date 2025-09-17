#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int INF = 2e9;

struct X {
    int v;
    int t;
    int p;
};

int Deiksrta(int start, vector<vector<X>> graph, int finish, int p) {
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
            if (road.p <= p) {
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

int main()
{

    int n, m;
    cin >> n >> m;

    vector<vector<X>> graph(m);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        int t;
        cin >> t;
        int p;
        cin >> p;

        X road;
        road.v = v;
        road.t = t;
        road.p = p;

        graph[u].push_back(road);
        road.v = u;
        graph[v].push_back(road);
    }
    int x;
    cin >> x;

    int p = 0, r = 0;
    int left = 0, right = 100000;
    while (left + 1 < right) {
        int middle = (left + right) / 2;
        int rast = Deiksrta(0, graph, x, middle);
        if (rast != -1) {
            right = middle;
            p = middle;
            r = rast;
        }
        else {
            left = middle + 1;
            p = middle;
            r = rast;
        }
        cout << middle << " " << rast << " " << left << " " << right << endl;

    }

    cout << p << " " << r;

    return 0;
}

