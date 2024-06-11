#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int h, n;
		cin >> h >> n;

		int a[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			h -= a[i];
		}

		int c[n], temp[n], min = INT_MAX;
		for (int i = 0; i < n; i++)
		{
			cin >> c[i];
			temp[i] = c[i];
			if(c[i] < min) {
				min = c[i];
			}
		}

		long long int count = 1;
		while(h > 0) {
			for (int i = 0; i < n; i++) {
				temp[i] -= min;
				if(temp[i] == 0) {
					h -= a[i];
					temp[i] = c[i];
				}
			}
			count += min;
			for (int i = 0; i < n; i++) {
				if(temp[i] < min) {
					min = temp[i];
				}
			}
		}

		cout << count << endl;
	}

	return 0;
}