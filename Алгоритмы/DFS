void DFS(vector<vector<int>>graph, vector<bool>& visited, int start) //поиск в глубину
{
    visited[start] = true;
    for (auto i : graph[start]) {
        if (!visited[i]) {
            DFS(graph, visited, i);
        }
    }
}
