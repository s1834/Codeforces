#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n, k;
        cin >> n >> k;

        int arr[n], grt = 1;
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
            if(i > 0 && grt && arr[i] < arr[i - 1]) grt = 0;
        }

        if(k > 1 || grt) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}

/* if k > 1 we can easily reverse and sort or if it is already sorted we return yes */