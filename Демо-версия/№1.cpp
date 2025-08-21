#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    
    int n, m;
    cin >> n >> m;
    vector<int> C(n);
    for (int i = 0; i < n; i++) {
        cin >> C[i];
    }
    vector<int> P(m);
    for (int i = 0; i < m; i++) {
        cin >> P[i];
    }

    sort(begin(C), end(C));
    sort(begin(P), end(P));

    int Count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < P.size(); j++) {
            if (C[i] <= P[j]) {
                Count++;
                P.erase(P.begin() + j);
            }
        }
    }

    cout << Count;
    
    return 0;
}

