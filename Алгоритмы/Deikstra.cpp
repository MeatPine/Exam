vector<int> dijkstra(int start, int n, const vector<vector<pair<int, int>>>& graph) {
    const int INF = INT_MAX;
    vector<int> dist(n, INF);
    dist[start] = 0;
    set<pair<int, int>> pq; // {distance, vertex}
    pq.insert({0, start});
    
    while (!pq.empty()) {
        int u = pq.begin()->second;
        int d = pq.begin()->first;
        pq.erase(pq.begin());
        
        if (d > dist[u]) continue; // Skip outdated entries
        
        for (const auto& edge : graph[u]) {
            int v = edge.first;
            int wt = edge.second;
            if (dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
                pq.insert({dist[v], v});
            }
        }
    }
    return dist;
}
