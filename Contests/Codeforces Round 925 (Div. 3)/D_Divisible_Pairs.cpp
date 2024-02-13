#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, x, y;
		cin >> n >> x >> y;

		int arr[n], count = 0;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			if(i > 0 && !((arr[0] + arr[i]) % x) && !((arr[0] - arr[i]) % y)) {
				count++;
			}
		}
		for (int i = 1; i < n - 1; i++) {
			for(int j = i + 1; j < n; j++) {
				if(!((arr[i] + arr[j]) % x) && !((arr[i] - arr[j]) % y)) {
					count++;
				}
			}
		}

		cout << count << endl;
	}

	return 0;
}