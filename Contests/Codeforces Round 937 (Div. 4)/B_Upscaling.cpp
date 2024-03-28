#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;

	string checkboard = "";
	while (t--) {
		int n;
		cin >> n;

		int countI = 0, countJ = 0;
		char symbol = '#';
	    if(n % 2) {
	        for (int i = 0; i < 2 * n; i++) {
			countJ = 0;
			countI++;
			if(countI == 2) {
			    symbol = symbol == '#' ? '.' : '#';
				countI = 0;
			}
			for (int j = 0; j < 2 * n; j++) {
				checkboard += symbol;
				countJ++;
				if(countJ == 2) {
					symbol = symbol == '#' ? '.' : '#';
					countJ = 0;
				}
			}
			checkboard += '\n';
		}
	    } else {
	        for (int i = 0; i < 2 * n; i++) {
			countJ = 0;
			countI++;
			for (int j = 0; j < 2 * n; j++) {
				checkboard += symbol;
				countJ++;
				if(countJ == 2) {
					symbol = symbol == '#' ? '.' : '#';
					countJ = 0;
				}
			}
			if(i > 2 * n - 1) {
			    continue;
			}
			checkboard += '\n';
			if(countI == 2) {
			    symbol = symbol == '#' ? '.' : '#';
				countI = 0;
			}
		}
	    }
	}
		cout << checkboard << endl;

	return 0;
}