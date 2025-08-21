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

    int lod = 0;
    int Count = 0;
    int left = 0, right = n - 1;
    while (left <= right) {
        if (tur[left] + tur[right] <= k) {
            lod = lod + tur[left] + tur[right];
            left++;
            right--;
            //cout << "if" << endl;
        }
        else {
            lod += tur[right];
            right--;
            //cout << "else" << endl;
        }
        
        if (lod >= k) {
            Count++;
            lod -= k;
        }

        if (left == right) {
            Count++;
            break;
        }
    }
    
    cout << Count;
    
    return 0;
}
