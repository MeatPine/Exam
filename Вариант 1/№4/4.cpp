#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> lab(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> lab[i][j];
        }
    }

    if (lab[n - 1][m - 1] < 0) {
        cout << "NO" << endl << 0;
        return 0;
    }

    vector<vector<int>> dp(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 && j == 0) {
                dp[i][j] = lab[i][j];
            }

            if (i == 0 && j > 0) {
                if (lab[i][j] < 0) {
                    dp[i][j] = 0;
                }
                else {
                    dp[i][j] = dp[i][j - 1] + lab[i][j];
                }
            }

            if (i > 0 && j == 0) {
                if (lab[i][j] < 0) {
                    dp[i][j] = 0;
                }
                else {
                    dp[i][j] = dp[i - 1][j] + lab[i][j];
                }
            }

            if (i > 0 && j > 0) {
                if (lab[i][j] < 0) {
                    dp[i][j] = 0;
                }
                else {
                    dp[i][j] = max(max(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]) + lab[i][j];
                }
            }
        }
    }

    if (dp[n - 1][m - 1] > 0) {
        cout << dp[n - 1][m - 1];
    }
    else {
        cout << "NO" << endl << dp[n - 1][m - 1];
    }

    return 0;
}
