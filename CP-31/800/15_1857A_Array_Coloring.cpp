#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        int odd = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if(a[i] % 2) odd++;
        }

        if(odd % 2) cout << "NO\n";
        else cout << "YES\n";
    }

    return 0;
}

/*
If the count of odd numbers is odd, then answer is "NO" else always "YES".
o + o = e
e + e = e
o + e = o
*/