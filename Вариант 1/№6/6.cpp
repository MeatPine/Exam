#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int INF = 2e9;

struct ROAD {
    int v;
    int t;
    int p;
};

vector<int> dijkstra(int start, int n, vector<vector<ROAD>> graph, int p) {
    vector<int> dist(n, INF);
    dist[start] = 0;
    set<pair<int, int>> pq;
    pq.insert({ 0, start });

    while (!pq.empty()) {
        int u = pq.begin()->second;
        int d = pq.begin()->first;
        pq.erase(pq.begin());

        if (d > dist[u]) continue;

        for (const auto& edge : graph[u]) {
            int road_p = edge.p;
            int v = edge.v;
            int wt = edge.t;
            if (dist[u] + wt < dist[v]) {
                if (road_p >= p) {
                    dist[v] = dist[u] + wt;
                    pq.insert({ dist[v], v });
                }
            }
        }
    }
    return dist;
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

    int x;
    cin >> x;
    /*
    vector<int> dist = dijkstra(0, n, graph, 1);
    for (int i = 0; i < dist.size(); i++) {
        cout << dist[i] << " ";
    }
    */
    vector<int> dist = dijkstra(0, n, graph, 0);
    if (dist[x] == INF)
    {
        cout << -1 << endl;
        return 0;
    }
    int left = 0, right = 100001;
    int l, k;
    l = 0;
    k = INF;
    while (left <= right) {
        int mid = (left + right) / 2;
        dist = dijkstra(0, n, graph, mid);
        cout << left << " " << right << " " << mid << " " << k << endl;
        if (dist[x] != INF) {
            left = mid + 1;
            l = mid;
            k = dist[x];
        }
        else {
            right = mid - 1;
        }
    }

    cout << k << " " << l;

    return 0;
}

/*
5 4
0 1 2 10
0 2 2 10
1 3 2 10
2 3 1 10
3

*/
