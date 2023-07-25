#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		int a[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
			int i = 0;
			for (int j = i + 1; j < n; j++) {
				if (((a[i] % 2 == 0 && a[j] % 2 == 0) || (a[i] % 2 != 0 && a[j] % 2 != 0)) && (a[j] < a[i])) {
					a[i] = a[i] + a[j];
					a[j] = a[i] - a[j];
					a[i] = a[i] - a[j];
					j = i;
				}

				if (j == n - 1) {
					i++;
					j = i;
				}
			}

		int flag = 1;
		for (int i = 0; i < n - 1; i++) {
			if (a[i] > a[i + 1]) {
				flag = 0;
				break;
			}
		}

		if (flag) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}

	return 0;
}