#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        long long int n, k;
        cin >> n >> k;
        if(n % 2 == 0 || (n - k) % 2 == 0) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}

/*
we need to check if 
2 ⋅ x + k ⋅ y = n
where x and y are non-negative integers.
If n is even, then we can always find such x and y as they will be divisible by 2 and y will be 0.
If n is odd, then n - k must be even, so that we can find such x and y as after subtracting k from n, it becomes even and divisible by 2.

NOTE: it requires long long int
*/