#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

    int n, k;
    cin >> n >> k;
    vector<int> sport(n);
    for (int i = 0; i < n; i++) {
        cin >> sport[i];
    }

    sort(begin(sport), end(sport));

    int MIN = 2000;
    for (int i = 0; i <= n - k; i++) {
        if (MIN > sport[i + k - 1] - sport[i]) {
            cout << "left " << sport[i] << " right " << sport[i + k - 1] << endl;
            MIN = sport[i + k - 1] - sport[i];
            cout << MIN << endl;
        }
        cout << "i " << i << endl;
    }

    cout << MIN;

    return 0;
}
