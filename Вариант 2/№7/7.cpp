/*
4 3 1
1 2
2 3 2
3 4 3
1 4 4
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int k;
	cin >> k;
	vector<vector<int>> road(m + k, vector<int>(3));
	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		road[i][0] = 0;
		road[i][1] = a - 1;
		road[i][2] = b - 1;
	}
	//cout << "x";
	for (int i = k; i < m + k; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		road[i][0] = c;
		road[i][1] = a - 1;
		road[i][2] = b - 1;
	}
	//cout << "x";

	//for (int i = 0; i < m + k; i++) {
		//cout << road[i][0] << " " << road[i][1] << " " << road[i][2] << endl;
	//}

	//cout << endl;

	sort(road.begin(), road.end());

	vector<int> comp(n);
	for (int i = 0; i < n; i++) {
		comp[i] = i;
	}

	int min_cost = 0;
	for (auto& r : road) {
		int start = r[1];
		int finish = r[2];
		//cout << "y" << endl;
		//cout << start << " " << finish << endl;
		if (comp[start] != comp[finish]) {
			min_cost += r[0];
			for (int i = 0; i < n; i++) {
				//cout << i << endl;
				if (comp[i] == comp[finish]) {
					comp[i] = comp[start];
				}
			}
		}
		//cout << "z" << endl;
	}

	int x = comp[0];
	for (int i = 0; i < n; i++) {
		if (comp[i] != x) {
			cout << -1;
			return 0;
		}
	}
	
	cout << min_cost;
}
