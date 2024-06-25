#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, t;
	cin >> n >> t;

	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	queue<int> q;
	int sum = 0, count = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
		q.push(a[i]);
		if(sum > t) {
			sum -= q.front();
			q.pop();
			count = (count > q.size()) ? count : q.size();
		}
	}
	
	count = (count > q.size()) ? count : q.size();
	cout << count;

	return 0;
}