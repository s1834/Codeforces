#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;

		int mat[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> mat[i][j];
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
			    int max = INT_MIN;
			    bool greater = true;
				if(greater && i - 1 >= 0) {
					if(mat[i][j] > mat[i - 1][j]) {
						greater = true;
						if(mat[i - 1][j] > max) {
							max = mat[i - 1][j];
						}
					} else {
						greater = false;
					}
				}
                
				if(greater && j - 1 >= 0) {
					if(mat[i][j] > mat[i][j - 1]) {
						greater = true;
						if(mat[i][j - 1] > max) {
							max = mat[i][j - 1];
						}
					} else {
						greater = false;
					}
				}

				if(greater && i + 1 < n) {
					if(mat[i][j] > mat[i + 1][j]) {
						greater = true;
						if(mat[i + 1][j] > max) {
							max = mat[i + 1][j];
						}
					} else {
						greater = false;
					}
				}

				if(greater && j + 1 < m) {
					if(mat[i][j] > mat[i][j + 1]) {
						greater = true;
						if(mat[i][j + 1] > max) {
							max = mat[i][j + 1];
						}
					} else {
						greater = false;
					}
				}

				if(greater && max != INT_MIN) {
					mat[i][j] = max;
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << mat[i][j] << " ";
			}
			cout << endl;
		}
	}

	return 0;
}