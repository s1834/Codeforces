#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
		int size = 25, max = 0, ans = 0, temp;

		for (int i = 0; i < size; i++) {
			temp = 0;
			if(prime[i] > n) {
				break;
			}

			for (int j = 0; j < n; j++) {
				if((j + 1) * prime[i] > n) {
					break;
				}
				temp += (j + 1) * prime[i]; 
			}

			if(temp > max) {
				max = temp;
				ans = prime[i];
			}
		}

		cout << ans << endl;
	}

	return 0;
}