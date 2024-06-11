#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		long long int a[n], prefixSum[n];
		prefixSum[0] = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if(i != 0) {
				prefixSum[i] = prefixSum[i - 1] + a[i - 1];
			}
		}

		int count = 0, max = 0;
		for (int i = 0; i < n; i++) {
			if(a[i] >= max) {
			    max = a[i];
			    if(max == prefixSum[i]) {
			        count++;
			    }
			} else {
			    if(max == prefixSum[i] - max + a[i]) {
			        count++;
			    }
			}
		}
		cout << count << endl;
	}

	return 0;
}