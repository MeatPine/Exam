int find(vector<int>& comp, int x) {
    if (comp[x] != x)
        comp[x] = find(comp, comp[x]);
    return comp[x];
}

int main()
{
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
    int edges_used = 0;


    for (auto & edge: edges){
        int weight = edge[0];
        int start  = edge[1];
        int end    = edge[2];

        int root_start = find(comp, start);
        int root_end = find(comp, end);

        if (root_start != root_end) {
            ans += weight;
            comp[root_end] = root_start; 
            edges_used++;
        }
 }
 
    if (edges_used != n - 1) {
        cout << "-1" << endl;
    } 
    else {
        cout << ans << endl;
    }
