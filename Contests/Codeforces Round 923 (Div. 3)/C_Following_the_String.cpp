#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int t;
	cin >> t;
 
	while (t--) {
		int n;
		cin >> n;
 
		vector<int> a(n);
		for(int i = 0; i < n; i++) {
			cin >> a[i];
		}
 
		map<int, vector<char>> mp;
		string s = "";
		for(int i = 0; i < n; i++) {
			if(mp[a[i]].size() == 0) {
				mp[a[i]].push_back('a');
				s += 'a';
			} else {
				char last = mp[a[i]].size() - 1;
				mp[a[i]].push_back(mp[a[i]][last] + 1);
				s += mp[a[i]][last + 1];
			}
		}
		cout << s << endl;
	}
 
	return 0;
}