const int INF = 1e9;
vector <int> dist (N, INF);
dist[0] = 0;
vector <bool> used (N, false);
int ans = 0;
for (int i = 0; i < N; ++i)
{
    int min_dist = INF, u;
    for (int j = 0; j < N; ++j)
        if (!used[j] && dist[j] < min_dist)
        {
            min_dist = dist[j];
            u = j;
        }
    ans += min_dist;
    used[u] = true;
    for (int v = 0; v < N; ++v)
        dist[v] = min(dist[v], W[u][v]);
}
