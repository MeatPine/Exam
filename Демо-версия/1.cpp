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

    int child = 0, present = 0;
    int Count = 0;
    while (child < n && present < m) {
        //cout << Count << " " << child << " " << present << endl;

        if (C[child] <= P[present]) {
            Count++;
            child++;
            present++;
        }
        else {
            present++;
        }
    }

    cout << Count;

    return 0;
}
