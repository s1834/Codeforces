#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

	    int sum = 0;
	    for (int i = 1; i <= n; i++) {
	    	int temp = i;
	    	while(temp != 0) {
	    		sum += temp % 10;
	    		temp /= 10;
	    	}
	    }

	    cout << sum << endl;
	}

	return 0;
}