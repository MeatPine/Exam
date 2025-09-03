#include <iostream>
#include <vector>

using namespace std;

int get_days(int n, int mid, vector<int> w) {
    int days = 1;
    int x = 0;
    int truck1 = 0, truck2 = 0;
    for (int i = 0; i < n; i++) {
        if (w[i] > 2 * mid)
        {
            return days;
        }

        if (truck1 + w[i] <= mid)
        {
            truck1 += w[i];
        }
        else if (truck2 + (w[i] - (mid - truck1)) <= mid)
        {
            int wt = w[i];
            wt -= mid - truck1;
            truck1 = mid;
            truck2 += wt;
        }
        else
        {
            days++;
            truck1 = w[i];
            if (w[i] > mid)
            {
                truck1 = mid;
                truck2 = w[i] - mid;
            }
            else
            {
                truck2 = 0;
            }
        }

    }

    return days;
}

int main() {
    int n;
    cin >> n;
    int d;
    cin >> d;
    vector<int> w(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> w[i];
    }
    long long left = 0;
    long long right = 2e9;
    while (left + 1 < right)
    {
        long long tonage = (left + right) / 2;
        long long truck1 = 0;
        long long truck2 = 0;
        long long count = 0;
        for (int i = 0; i < n; ++i)
        {
            if (w[i] > 2 * tonage)
            {
                count = d + 1;
                break;
            }
            if (truck1 + w[i] <= tonage)
            {
                truck1 += w[i];
            }
            else if (truck2 + (w[i] - (tonage - truck1)) <= tonage)
            {
                int wt = w[i];
                wt -= tonage - truck1;
                truck1 = tonage;
                truck2 += wt;
            }
            else
            {
                count++;
                truck1 = w[i];
                if (w[i] > tonage)
                {
                    truck1 = tonage;
                    truck2 = w[i] - tonage;
                }
                else
                {
                    truck2 = 0;
                }
            }
        }

        count++;

        if (count > d) {
            left = tonage;
        }
        else {
            right = tonage;
        }

    }
    cout << right << endl;
    cout << get_days(n, right, w);

    return 0;
}
