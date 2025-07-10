#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        int mx = 0, mn = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            mx = a[mx] < a[i] ? i : mx;
            mn = a[mn] > a[i] ? i : mn;
        }

        if(mx == mn) cout << "NO\n";
        else {
            cout << "YES\n";
            a[0] = a[0] + a[mx];
            a[mx] = a[0] - a[mx];
            a[0] = a[0] - a[mx];
            for(int i = 0; i < n; i++) cout << a[i] << " ";
            cout << endl;;
        }
    }

    return 0;
}

/*
If the max and min of array is equal, or simply put the whole array is having same number 'x', then asn is "NO" else answer is "YES".
*/