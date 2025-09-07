#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int X = -100001;

int main() {
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> lab(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            string a;
            cin >> a;
            if (a == "x") {
                lab[i][j] = X;
            }
            else {
                lab[i][j] = stoi(a);
            }
        }
    }

    vector<vector<int>> dp(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            
            cout << i << " " << j << endl;

            if (i == 0 && j == 0) {
                dp[i][j] = lab[i][j];
            }

            if (i == 0 && j > 0) {
                if (lab[i][j] == X) {
                    dp[i][j] = X;
                }
                else{
                    if (dp[i][j - 1] = X) {
                        dp[i][j] = X;
                    }
                    else {
                        dp[i][j] = dp[i][j - 1] + lab[i][j];
                    }
                }
            }

            if (i > 0 && j == 0) {
                if (lab[i][j] == X) {
                    dp[i][j] = X;
                }
                else {
                    if (dp[i - 1][j] = X) {
                        dp[i][j] = X;
                    }
                    else {
                        dp[i][j] = dp[i - 1][j] + lab[i][j];
                    }
                }
            }

            if (i > 0 && j > 0) {
                if (lab[i][j] == X) {
                    dp[i][j] = X;
                }
                else {
                    if (dp[i - 1][j] != X && dp[i][j - 1] != X && dp[i - 1][j - 1] != X) {
                        dp[i][j] = max(max(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]);
                    }
                    
                    if (dp[i - 1][j] != X && dp[i][j - 1] != X && dp[i - 1][j - 1] == X) {
                        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                    }

                    if (dp[i - 1][j] == X && dp[i][j - 1] != X && dp[i - 1][j - 1] != X) {
                        dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - 1]);
                    }

                    if (dp[i - 1][j] != X && dp[i][j - 1] == X && dp[i - 1][j - 1] != X) {
                        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]);
                    }

                    if (dp[i - 1][j] == X && dp[i][j - 1] == X && dp[i - 1][j - 1] != X) {
                        dp[i][j] = dp[i - 1][j - 1] + lab[i][j];
                    }

                    if (dp[i - 1][j] == X && dp[i][j - 1] != X && dp[i - 1][j - 1] == X) {
                        dp[i][j] = dp[i][j - 1] + lab[i][j];
                    }

                    if (dp[i - 1][j] != X && dp[i][j - 1] == X && dp[i - 1][j - 1] == X) {
                        dp[i][j] = dp[i - 1][j] + lab[i][j];
                    }

                    if (dp[i - 1][j] == X && dp[i][j - 1] == X && dp[i - 1][j - 1] == X) {
                        dp[i][j] = X;
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
