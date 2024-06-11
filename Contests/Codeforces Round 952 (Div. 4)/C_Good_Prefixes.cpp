#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		long long int a[n], prefixSum[n][2];
		prefixSum[0][0] = 0;
		prefixSum[0][1] = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if(i != 0) {
				prefixSum[i][0] = prefixSum[i - 1][0] + a[i - 1];
				prefixSum[i][1] = prefixSum[i - 1][1] > a[i] ? prefixSum[i - 1][1] : a[i];
			}
		}

		int count = 0;
		for (int i = 0; i < n; i++) {
			if(prefixSum[i][0] - prefixSum[i][1] + a[i] == prefixSum[i][1]) {
				count++;
			}
		}
		cout << count << endl;
	}

	return 0;
}