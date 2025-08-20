int n, m;
cin >> n >> m;
vector <vector <int> > edges(m, vector<int>(3));
for (int i = 0; i < m; ++i)
    cin >> edges[i][1] >> edges[i][2] >> edges[i][0];
sort(edges.begin(), edges.end());
vector <int> comp(n);
for (int i = 0; i < n; ++i)
    comp[i] = i;
int ans = 0;
for (auto & edge: edges)
{
    int weight = edge[0];
    int start  = edge[1];
    int end    = edge[2];
    if (comp[start] != comp[end])
    {
        ans += weight;
        int a = comp[start];
        int b = comp[end];
        for (int i = 0; i < n; ++i)
            if (comp[i] == b)
                comp[i] = a;
     }
 }
