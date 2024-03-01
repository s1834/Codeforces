#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> v;
		int temp;
		for (int i = 0; i < n; i++) {
			cin >> temp;
			v.push_back(temp);
		}

		sort(v.begin(), v.end());
		cout << abs(v[0] - v[n - 2]) + abs(v[n - 2] - v[1]) + abs(v[1] - v[n - 1]) + abs(v[n - 1] - v[0]) << endl;
	}

	return 0;
}