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
        
        bool zero = false;
        int count = 0;
        for(int i = 0; i < n; i++) {
            if(!zero && a[i] == 0) {
                zero = true;
                count++;
            }
            if(zero && a[i] != 0) {
                zero = false;
            }
        }
        cout << count << endl;
    }

    return 0;
}

/*

*/