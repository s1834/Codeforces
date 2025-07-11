#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        
        string s;
        cin >> s;

        int l = 0, r = n - 1;
        while(l < r && s[l] != s[r]) {
            l++;
            r--;
        }
        cout << r - l + 1<< endl;
    }

    return 0;
}

/*
we simply keep decreasing the size until we dont find same (either 1-1 or 0-0) at both ends.
*/