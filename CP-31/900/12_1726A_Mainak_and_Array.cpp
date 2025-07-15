#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];


        int ans = a[n - 1] - a[0];
        for(int i = 1; i < n; i++) ans = max(ans, a[i] - a[0]);
        for(int i = 0; i < n - 1; i++) ans = max(ans, a[n - 1] - a[i]);
        for(int i = 0; i < n - 1; i++) ans = max(ans, a[i] - a[i + 1]);
        cout << ans << endl;
    }

    return 0;
}

/*
1) first check the difference between the first and last element
2) then check the difference between the first element and all other elements
3) then check the difference between the last element and all other elements
4) finally check the difference between all adjacent elements
*/