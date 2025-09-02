#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    
    int n;
    cin >> n;
    n++;
    vector<int> C(n);
    for (int i = 0; i < n; i++) {
        cin >> C[i];
    }
    vector<int> H(n);
    for (int i = 0; i < n; i++) {
        cin >> H[i];
    }

    vector<int> dp(n);
    dp[0] = C[0];

    for (int i = 1; i < n; i++) {
        cout << i << endl;
        int MIN = 100;
        for (int j = 0; j < i; j++) {
            if (H[j] >= i - j) {
                cout << MIN << " " << dp[j] << endl;
                MIN = min(MIN, dp[j]);
            }
        }
        dp[i] = MIN + C[i];
    }

    for (int i = 0; i < n; i++) {
        cout << dp[i] << " "; 
    }

    cout << endl;

    cout << dp[n - 1];

    return 0;
}


