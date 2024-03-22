#include <bits/stdc++.h>
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

		sort(a, a + n);
		int median = a[n % 2 ? n / 2 : n / 2 - 1], count = 0;
		for (int i = (n % 2 ? n / 2 + 1 : n / 2) - 1; i < n; i++) {
			if(a[i] == median) {
				count++;
			} else {
				break;
			}
		}

		cout << count << endl;
	}

	return 0;
}