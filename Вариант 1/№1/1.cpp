#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

    int n, k;
    cin >> n >> k;
    vector<int> tur(n);
    for (int i = 0; i < n; i++) {
        cin >> tur[i];
    }

    sort(begin(tur), end(tur));

    int Count = 0;
    int left = 0, right = n - 1;
    while (left <= right) {
        if (tur[left] + tur[right] <= k) {
            left++;
            right--;
            Count++;
            //cout << "if" << endl;
        }
        else {
            Count++;
            right--;
            //cout << "else" << endl;
        }

        if (left == right) {
            Count++;
            break;
        }
    }

    cout << Count;

    return 0;
}
