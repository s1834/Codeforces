#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        long long n, a, b;
        cin >> n >> a >> b;
        if(a + b + 2 <= n || (a == b && a == n))cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}

/*
we need to find p and q such that:
1) prefix of p & q is equal to a
2) suffix of p & q is equal to b

so we simply check if a + b + 2 <= n, which means we can have at least two elements in the middle that can be different in both p & q.
a == b == n is the only edge case for it.
*/