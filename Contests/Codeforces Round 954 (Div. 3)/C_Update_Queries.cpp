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

		vector<char> character;
		for (int i = 0; i < m; i++) {
			character.push_back(c[i]);
		}


		int index = 0;
		for (int i = 0; i < m; i++) {
			if(ind[i] - 1 >= index) {
				s[ind[i] - 1] = character[index];
				index++;
			}	
		}

		cout << s << endl;
	}

	return 0;
}