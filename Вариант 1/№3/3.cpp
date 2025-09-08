#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, c;
    cin >> n >> c;
    vector<int> w(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    vector<int> k(n);
    for (int i = 0; i < n; i++) {
        cin >> k[i];
    }

    vector<int> dp(n);
    dp[0] = w[0];

    for (int i = 1; i < n; i++) {
        //cout << i << endl;
        int MIN = 100001;
        for (int j = 0; j < i; j++) {
            if (k[j] >= i - j) {
                //cout << MIN << " " << dp[j] << endl;
                MIN = min(MIN, dp[j] + k[j]*c);
            }
        }
        dp[i] = MIN + w[i];
    }

    for (int i = 0; i < n; i++) {
        cout << dp[i] << " ";
    }

    cout << endl;

    cout << dp[n - 1];

    return 0;
}
