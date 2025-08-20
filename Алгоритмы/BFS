void bfs(int start, vector<vector<int>>graph, vector<bool>&visited) //поиск в ширину
{
    queue<int> Q;
    Q.push(start);
    visited[start] = true;
    while (!Q.empty()) {
        int node = Q.front();
        Q.pop();
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                Q.push(neighbor);
            }
        }
    }
}

vector<bool> Visited (n, False);
bfs(0, graph, Visited)
