#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		int arr[n], sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			if(arr[i] >= 0) {
				sum += arr[i];
			} else {
				sum += arr[i] * -1;
			}
		}

		cout << sum << endl;
	}

	return 0;
}