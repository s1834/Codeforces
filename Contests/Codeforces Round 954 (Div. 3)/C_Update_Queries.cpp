#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;

		string s;
		cin >> s;

		vector<int> ind(m);
		for (int i = 0; i < m; i++) {
			cin >> ind[i];
		}

		string c;
		cin >> c;

		sort(ind.begin(), ind.end());
		sort(c.begin(), c.end());

		unordered_map<int, char> character;
		int index = 0;
		for (int i = 0; i < m; i++) {
			if(character.find(ind[i]) == character.end()) {
				character[ind[i]] = c[index];
				index++;
			}
		}


		for (auto x : character) {
			s[x.first - 1] = x.second;
		}

		cout << s << endl;
	}

	return 0;
}