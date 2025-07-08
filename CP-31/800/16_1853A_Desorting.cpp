#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        int mn = INT_MAX, l = -1,  r = -1;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if(i > 0 && mn > a[i] - a[i - 1]) {
                mn = a[i] - a[i - 1];
                l = a[i - 1];
                r = a[i];
            }
        }

       if(mn < 0) cout << 0 << endl;
       else cout << ((r - l) / 2) + 1 << endl;
    }
    
    return 0;
}

/*
1) We need to desort the array
2) This means we need to make sure no two adjacent elements are in increasing order
3) so we need to find the minimum difference between two adjacent elements
4) if the minimum difference is negative, then the array is already desorted
5) if the minimum difference is positive, then we can desort the array by increasing l and decreasing r
the number of ways to desort the array is (r - l) / 2 + 1
*/