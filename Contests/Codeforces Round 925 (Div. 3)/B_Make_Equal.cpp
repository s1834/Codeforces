#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		int min = 0, arr[n];
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			min += arr[i];
		}

		if(min % n != 0) {
			cout << "NO\n";
		} else {
			min /= n;
			int bucket = 0, flag = 1;
			for(int i = 0; i < n; i++) {
				if(arr[i] == min) {
					continue;
				}
				if(arr[i] > min) {
					bucket += arr[i] - min;
				} else {
					if(bucket + arr[i] >= min) {
						bucket -= min - arr[i];
					} else {
						cout << "NO\n";
						flag = 0;
						break;
					}
				}
			}
			if(flag) {
				cout << "YES\n";
			}
		}

	}

	return 0;
}