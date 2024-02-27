#include <bits/stdc++.h>
using namespace std;

int power(int base, int power) {
	int pow = 1;
	for (int i = 0; i < power; i++) {
		pow *= base;
	}
	return pow;
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		int a, b, l;
		cin >> a >> b >> l;

		set<int> s;

		if(l % a != 0 && l % b != 0) {
			s.insert(1);
		} else if(l % a == 0 && l % b == 0) {
			for (int i = 0; i < l; i++) {
				if(power(a, i) > l) {
					break;
				}
				for (int j = 0; j < l; j++) {
					if((power(a, i) * power(b, j)) > l) {
						break;
					}
					if(l % (power(a, i) * power(b, j)) == 0) {
						s.insert(l / (power(a, i) * power(b, j)));
					}
				}
			}
		} else if(l % a == 0) {
			for (int i = 0; i < l; i++) {
				if(power(a, i) > l) {
					break;
				}
				if(l % power(a, i) == 0) {
					s.insert(l / power(a, i));
				}
			}
		} else {
			for (int i = 0; i < l; i++) {
				if(power(b, i) > l) {
					break;
				}
				if(l % power(b, i) == 0) {
					s.insert(l / power(b, i));
				}
			}
		}

		

		cout << s.size() << endl;
	}

	return 0;
}