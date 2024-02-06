#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		string s;
		cin >> s;

		int start = 0, end = 0, flag = 0;
		for(int i = 0; i < n; i++) {
			if(s[i] == 'B' && !flag) {
				start = i;
				flag = 1;
			}
			if(s[i] == 'B')  {
				end = i;
			}
		}

		cout << end - start + 1 << endl;
	}

	return 0;
}