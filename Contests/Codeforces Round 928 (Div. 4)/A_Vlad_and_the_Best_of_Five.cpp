#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		string s;
		cin >> s;
		int count = 0;
		for (int i = 0; i < 5; i++) {
			if(s[i] == 'A') {
				count++;
			}
		}
		if(count > 2) {
			cout << "A\n";
		} else {
			cout << "B\n";
		}
	}

	return 0;
}