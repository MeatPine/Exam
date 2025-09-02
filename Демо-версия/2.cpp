#include <iostream>
#include <vector>

using namespace std;

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
        long long count = 0;
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
            else
            {
                count++;
                truck1 = w[i];
            }
        }
        count++;
        
        if (count > d) {
            left = tonage;
        }
        else {
            right = tonage;
        }
        
        cout << tonage << " " << truck1 << " " << count << endl;
    }
    cout << right;

    return 0;
}
