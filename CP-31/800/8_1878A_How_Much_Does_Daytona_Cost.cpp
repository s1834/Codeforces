#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        bool flag = false;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if(a[i] == k) flag = true;
        }
        if(flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}

/*
we need to find the subsegment where k has the most number of occurences
so the segment could be of length 1 too, that means if k is present in the array then we can return YES
*/