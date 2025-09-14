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
