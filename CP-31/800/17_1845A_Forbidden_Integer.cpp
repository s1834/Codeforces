#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, k, x;
        cin >> n >> k >> x;

        if(x != 1) {
            cout << "YES\n";
            cout << n << endl;
            for(int i = 0; i < n; i++) cout << 1 << " ";
            cout << endl;
        } else {
            if(k == 1 || (k == 2 && n % 2)) cout << "NO\n";
            else {
                cout << "YES\n";
                if(n % 2 == 0) {
                    cout << n / 2 << endl;
                    for(int i = 0; i < n / 2; i++) cout << 2 << " ";
                    cout << endl;
                } else {
                    cout << (n - 3) / 2 + 1 << endl;
                    for(int i = 0; i < (n - 3) / 2; i++) cout << 2 << " ";
                    cout << 3 << endl;;
                }
            }
        }
    }
    
    return 0;
}

/*
1) if x != 1, we can always use 1s to fill the array
2) if x == 1, we cannot use 1s, so we can only use 2s and 3s
3) if k == 1, we cannot use 2s or 3s, so we cannot fill the array
4) if k == 2, we can only use 2s, so we can only fill the array if n is even
5) if k >= 3, we can use 2s and 3s, so we can fill the array
6) if n is even, we can fill the array with 2s
7) if n is odd, we can fill the array with (n - 3) / 2 2s and one 3
*/