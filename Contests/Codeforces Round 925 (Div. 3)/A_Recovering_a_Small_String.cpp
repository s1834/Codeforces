#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int t;
	cin >> t;
 
	while (t--) {
		int n;
		cin >> n;
 
		string ans = "";
		int count = 3;
		while (n >= 26) {
			ans += 'z';
			n -= 26;
			count--;
		}
 
		if(count == 1) {
			ans += 'a' + n - 1;
		} else if(count == 2) {
			ans += 'a' + n - 2;
			ans += 'a';
		} else if(count == 3) {
			ans += 'a' + n - 3;
			ans += 'a';
			ans += 'a';
		}
 
		reverse(ans.begin(), ans.end());
		cout << ans << endl;
	}
 
	return 0;
}