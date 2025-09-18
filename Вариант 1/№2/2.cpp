#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    int d;
    cin >> d;
    vector<int> w(n);
    int left = 0;
    int right = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> w[i];
        right += w[i];
    }
    while (left + 1 < right)
    {
        long long tonage = (left + right) / 2;
        long long truck1 = 0;
        long long truck2 = 0;
        long long count = 1;
        for (int i = 0; i < n; ++i)
        {
            if (w[i] > tonage)
            {
                count = d + 1;
                break;
            }
            if (truck1 + w[i] <= tonage)
            {
                truck1 += w[i];
            }
            else if (truck2 + w[i] <= tonage)
            {
                truck2 += w[i];
            }
            else
            {
                count++;
                if (count > d) {
                    break;
                }
                truck1 = w[i];
                truck2 = 0;
            }
        }

        //count++;

        if (count > d) {
            left = tonage;
        }
        else {
            right = tonage;
        }

    }
    cout << right;

    return 0;
}
