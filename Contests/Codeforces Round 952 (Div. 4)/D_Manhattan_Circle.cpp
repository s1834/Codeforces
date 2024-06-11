#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;

		char grid[n][m];
		int maxHashes = 0, tempHashes, indI = 0, indJ = 0;
		bool compare = true;
		for (int i = 0; i < n; i++) {
			tempHashes = 0;
			for (int j = 0; j < m; j++) {
			    cin >> grid[i][j];
				if(compare && grid[i][j] == '#') {
					tempHashes++;
				}
 			}
 			if(compare && tempHashes > maxHashes) {
 				maxHashes = tempHashes;
 			    indI = i;
 			}
 			
 			if(compare && tempHashes < maxHashes) {
 			    compare = false;
 			}
		}

		for(int i = 0; i < m; i++) {
			if(grid[indI][i] == '#') {
				indJ = i + (maxHashes / 2);
				break;
			}
		}

		cout << indI + 1 << " " << indJ + 1 << endl;
	}

	return 0;
}