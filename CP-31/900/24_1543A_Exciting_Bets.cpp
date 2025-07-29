#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        long long a, b;
        cin >> a >> b;

       if(b > a) swap(a, b);

       if(a == b) cout << 0 << " " << 0 << endl;
       else {
        long long gcd = a - b;
        long long moves = min(b % gcd, gcd - (b % gcd));
        cout << gcd << " " << moves << endl;
       }
    }

    return 0;
}


/*
if a > b, then we can say that gcd is always greater than or equal to a - b, and by this we can say a is constant and we are then only changing b to reach that gcd.
so we calculate b % gcd, to go to the previous multiple of gcd and we do gcd - (b % gcd) to go to the next multiple of gcd, and we take the minimum of these two values as the number of moves required to reach the gcd.
*/