#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int a[3];
		for (int i = 0; i < 3; i++) {
			cin >> a[i];
		}

		int min = INT_MAX;
		for (int i = 0; i < 3; i++) {
			int temp = 0;
			for (int j = 0; j < 3; j++) {
				temp += abs(a[i] - a[j]);
			}
			if(min > temp) {
				min  = temp;
			}
		}
		cout << min << endl;
	}

	return 0;
}