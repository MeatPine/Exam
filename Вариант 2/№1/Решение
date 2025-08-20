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

    int left = 0, right = k - 1;
    int MIN = 2000;
    for (int i = 0; i < n - k; i++) {
        //cout << left << " " << right << " " << MIN << endl;
        if (MIN > sport[right] - sport[left]) {
            MIN = sport[right] - sport[left];
            left++;
            right++;
        }
    }

    cout << MIN;

    return 0;
}

