/*
5 4
10 20 30 40 50
s 1 3
u 2 25
s 2 4
s 1 5
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

void Update(int n, int ind, int new_value, vector<int>& tree, vector<int>& arr) {
    int dift = new_value - tree[ind + n - 1];
    arr[ind] = new_value;
    ind += n - 1;
    tree[ind] = new_value;
    int parent = 0;
    while (ind > 0) {
        if (ind % 2 == 0) {
            parent = (ind - 2) / 2;
        }
        else {
            parent = (ind - 1) / 2;
        }
        tree[parent] += dift;
        ind = parent;
    }
}

int Get_Sum(int n, int left, int right, vector<int> tree) {
    left += n - 1;
    right += n - 1;
    int SUM = 0;
    while (left < right) {
        if (left % 2 == 0) {
            SUM += tree[left];
            left++;
        }

        if (right % 2 != 0) {
            SUM += tree[right];
            right--;
        }

        else {
            if (right % 2 == 0) {
                SUM += tree[right];
                right--;
            }

            if (left % 2 != 0) {
                SUM += tree[left];
                left++;
            }
        }

    }
    return SUM;

}

int main()
{

    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<string> U(q);
    vector<int> I(q);
    vector<int> X(q);
    for (int i = 0; i < q; i++) {
        cin >> U[i];
        cin >> I[i];
        cin >> X[i];
    }

    int y = log2(n) + 1;
    for (int i = arr.size(); i < pow(2, y); i++) {
        arr.push_back(0);
    }
    int n_old = n;

    n = arr.size();

    vector<int> tree(2 * n - 1);
    for (int i = 0; i < n; i++) {
        tree[i + n - 1] = arr[i];
    }

    for (int i = n - 2; i >= 0; i--) {
        tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
    }

    for (int i = 0; i < q; i++) {
        if (U[i] == "s") {
            int SUM = Get_Sum(n, I[i], X[i], tree);
            cout << SUM << endl;
        }
        if (U[i] == "u") {
            Update(n, I[i] - 1, X[i], tree, arr);
        }
    }

    return 0;
}
