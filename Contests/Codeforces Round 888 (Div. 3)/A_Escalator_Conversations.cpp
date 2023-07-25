#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, m, k, H;
		cin >> n >> m >> k >> H;

		int h[n];
		for (int i = 0; i < n; i++) {
			cin >> h[i];
		}

		int temp, cnt, convo = 0;
		for (int i = 0; i < n; i++) {
			cnt = 1;
			for (int j = cnt + 1; j <= m; j++) {
				if (abs(H - h[i]) == abs((cnt * k) - (j * k))) {
					convo++;
					break;
				}
				if (j == m) {
					cnt++;
					j = cnt + 1;
				}
			}
		}

		cout << convo << endl;
	}

	return 0;
}
