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

        int ops = 0;
        for(int i = 0; i < n - 1; i++) if(a[i] % 2 == a[i + 1] % 2) ops++;
        cout << ops << endl;
    }

    return 0;
}

/*
array 'a' is good if no two adjacent elements have the different parity.

if i have a segment, 's' of elements of same parity than I want to reduce them to a single number by n - 1 operations.
*/