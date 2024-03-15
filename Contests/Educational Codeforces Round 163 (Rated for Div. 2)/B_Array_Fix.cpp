#include <bits/stdc++.h>
using namespace std;

int ind;

vector<int> insrt(int n) {
	vector<int> temp;
	while(n) {
		temp.push_back(n % 10);
		n /= 10;
	}
	reverse(temp.begin(), temp.end());
	return temp;
}

bool check(vector<int> v) {
	int n = v.size();
	for (int i = 1; i < n; i++) {
		if(v[i] < v[i - 1]) {
			ind = i - 1;
			return false;
		}
	}

	return true;
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> v(n);
		bool flag = true;
		for (int i = 0; i < n; i++) {
			cin >> v[i];

			if(flag && i > 0 && v[i] < v[i - 1]) {
				flag = false;
				ind = i - 1;
			}
		}

		if(flag) {
			cout << "YES\n";
		} else {
		    int count = 0;
			while(!flag && count <= n) {
				vector<int> temp = insrt(v[ind]);
				v.erase(v.begin() + ind, v.begin() + ind + 1);
				v.insert(v.begin() + ind, temp.begin(), temp.end());
				flag = check(v);
				count++;
			}
			
			if(flag) {
			    cout << "YES\n";
			} else {
			    cout << "NO\n";
			}
		}
	}

	return 0;
}