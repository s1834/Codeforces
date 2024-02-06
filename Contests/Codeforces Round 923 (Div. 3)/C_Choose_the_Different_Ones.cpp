#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, m, k;
		cin >> n >> m >> k;

		map<int, int> mp1, mp2;
		
		int a;
		for(int i = 0; i < n; i++) {
			cin >> a;
			if(a <= k) {
				mp1[a]++;
			}
		}

		for(int i = 0; i < m; i++) {
			cin >> a;
			if(a <= k) {
				mp2[a]++;
			}
		}

		int size1 = mp1.size(), size2 = mp2.size();

		if (size1 < k / 2 || size2 < k / 2) {
			cout << "NO\n";
		} else {

        	for (auto i : mp1) {
            	mp2[i.first] += i.second;
        	}
        
        	size2 = mp2.size();
        	if(size2 < k) {
            	cout << "NO\n";
            	continue;
        	}

			int flag = 1;
			for(auto i : mp2) {
				if(i.second < 1) {
					cout << "NO\n";
					flag = 0;
					break;
				}
			}
			if(flag) {
				cout << "YES\n";
			}

		}
	}

	return 0;
}