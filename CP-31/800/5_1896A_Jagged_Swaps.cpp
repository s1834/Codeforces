#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        int flag = true;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if(a[i] != i && a[i] != i + 1 && a[i] != i + 2) flag = false;
        }
        if(flag) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

/*
*/