#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        long long int n;
        cin >> n;
        
        if(n < 4 || n % 2) cout << -1 << endl;
        else {
            long long x = ceil(n * 1.0 / 6);
            long long y = n / 4;
            cout << x << " " << y << endl;
        }
    }
    return 0;
}


/*
if n < 4 or n is odd, then we cannot devide the tires such that all tires are utilized in the buses of size 4 and 6 tires.
*/