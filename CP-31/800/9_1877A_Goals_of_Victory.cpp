#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        
        vector<int> a(n);
        int ans = 0;
        for(int i = 0; i < n - 1; i++) {
            cin >> a[i];
            ans += a[i];
        }
        cout << ans * -1 << endl;
    }
    return 0;
}

/*
The question is a bit confusing, but the logic is simple once we see the testcases.
we just need to sum all and change the sign of the sum to get the answer.
*/