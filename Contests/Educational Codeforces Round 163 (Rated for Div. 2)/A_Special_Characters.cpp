#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		if (n % 2) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
			string ans;
			while (n) {
				ans += "AA";
				ans += "B";
				n -= 2;
			}
			cout << ans << endl;

		}
	}

	return 0;
}