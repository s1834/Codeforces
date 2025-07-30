#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        long long a, b, c;
        cin >> a >> b >> c;

       long long newA = 2 * b - c, newB = (a + c) / 2, newC = 2 * b - a;
       if((newA / a > 0 && newA % a == 0) || (newB / b > 0 && newB % b == 0 && (c - a) % 2 == 0) || (newC / c > 0 && newC % c == 0)) cout << "YES\n";
       else cout << "NO\n";
    }

    return 0;
}


/*
By formula 2b = a + c, We can dereive three possiblities:
1) am = 2b - c
    -> m = (2b - c) / a > 0
    -> (2b - c) % a == 0
2) bm = (a + c) / 2
    -> m = (a + c) / 2b > 0
    -> ((a + c) / 2) % b == 0
    -> (c - a) % 2 == 0 {since it to be an AP, b should be in the middle of a and c)
3) cm = 2b - a}
    -> m = (2b - a) / c > 0
    -> (2b - a) % c == 0
If any of these conditions are satisfied, then we can say that it is possible to make an AP with the given numbers a, b, and c.
*/