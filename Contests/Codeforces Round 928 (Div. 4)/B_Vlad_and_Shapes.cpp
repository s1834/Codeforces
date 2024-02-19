#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

	    string s;
	    set<char> st;
	    int one;
		for (int i = 0; i < n; i++) {
			cin >> s;
			one = 0;
			for (int j = 0; j < n; j++) {
			    if(s[j] == '1') {
			        one++;
			    }
			}
			if(one) {
			    st.insert(one);
			}
		}

		if(st.size() == 1) {
			cout << "SQUARE\n";
		} else {
			cout << "TRIANGLE\n";
		}
	}

	return 0;
}