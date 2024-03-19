#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		long long int a, b, c;
		cin >> a >> b >> c;


		if(b % 3 == 0 || (c >= 1 && (b + 1) % 3 == 0) || (c >= 2 && (b + 2) % 3 == 0)){
			cout << a + ((b + c) / 3) + ((b + c) % 3 ? 1 : 0) << endl;
		} else {
			cout << -1 << endl;
		}
	}

	return 0;
}