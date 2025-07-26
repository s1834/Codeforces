#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        long long int n;
        cin >> n;

        while(n % 2 == 0) n /= 2;

        if(n > 1) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}


/*
If n is a power of 2 then the answer is "NO", else "YES".

Before the unknowing of calculation of time complexity confused me.
*/