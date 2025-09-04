#include <iostream>
#include <vector>

using namespace std;

int get_days(int n, int mid, vector<int> w) {
    int days = 1;
    int x = 0;
    for (int i = 0; i < n; i++) {
        if (w[i] > mid) {
            return 1e9;
        }

        if (x + w[i] <= mid) {
            x += w[i];
            //cout << i << " " << x << endl;
        }
        else {
            days++;
            x = w[i];
            //cout << i << " " << x << endl;
        }
    }

    return days;
}

int main() {
    int d, n;
    cin >> d >> n;
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
        int count = get_days(n, tonage, w);

        if (count > d) {
            left = tonage;
        }
        else {
            right = tonage;
        }

        //cout << tonage << " " << truck1 << " " << count << endl;
    }
    cout << right;
    //cout << get_days(n, right, w);

    return 0;
}
