#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        int mx = INT_MIN, count = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if(!a[i]) count++;
            if(a[i]) {
                mx = max(mx, count);
                count = 0;
            }
        }
        cout << max(mx, count) << endl;
    }

    return 0;
}

/*
simply check for maximum consecutive zeroes
*/