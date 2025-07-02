#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n, x;
        cin >> n >> x;

        int arr[n], mx = 0;
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
            if(i > 0 && arr[i] - arr[i - 1] > mx) mx = arr[i] - arr[i - 1];
        }
        if(n == 1) cout << arr[0] << endl;
        else cout << max(mx, 2 * (x - arr[n - 1])) << endl;
    }

    return 0;
}

/*  */