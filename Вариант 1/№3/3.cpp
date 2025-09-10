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

    vector<int> dp(n, 100001);
    dp[0] = w[0];

    /*
    for (int i = 1; i < n; i++) {
        //cout << i << endl;
        int MIN = 100001;
        for (int j = 0; j < i; j++) {
            if (k[j] >= i - j) {
                //cout << MIN << " " << dp[j] << endl;
                MIN = min(MIN, dp[j] + (i - j) * c);
            }
        }
        dp[i] = MIN + w[i];
    }
    */

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < min(n, i + k[i] + 1); j++) {
            cout << "i " << i << " j " << j << endl;
            int x = dp[i] + (j - i) * c + w[j];
            cout << "x " << x << endl;
            if (dp[j] > x) {
                dp[j] = x;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << dp[i] << " ";
    }

    cout << endl;

    cout << dp[n - 1];

    return 0;
}

    return 0;
}
