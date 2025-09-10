#include <iostream>
#include <vector>

using namespace std;

int get_days(int n, int mid, vector<int> w) {
    int days = 1;
    int x = 0;
    int truck1 = 0, truck2 = 0;
    for (int i = 0; i < n; i++) {
        if (w[i] > mid)
        {
            return 100001;
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
            truck2 = 0;
        }

    }

    return days;
}


int main() {
    int n;
    cin >> n;
    int D;
    cin >> D;
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

        int mid = left + (right - left) / 2;
        //cout << left << " " << right << " " << get_days(n, mid, w) << endl;
        int d = get_days(n, mid, w);

        if (d < D) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    //cout << endl;

    //cout << left << " " << right << " " << get_days(n, right, w) << endl;

    cout << right;

    return 0;
}


/*
5 2
4 1 3 2 5

5
*/

/*
6 3
3 2 2 4 1 4
*/
