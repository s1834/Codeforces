#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        if(n < 11) cout << n << endl;
        else if(n < 101) cout << 9 + n / 10 << endl;
        else if(n < 1001) cout << 18 + n / 100 << endl;
        else if(n < 10001) cout << 27 + n / 1000 << endl;
        else if(n < 100001) cout << 36 + n / 10000 << endl;
        else  cout << 45 + n / 100000 << endl;
    }

    return 0;
}

/*
Check constraints: 1 ≤ 𝑛 ≤ 999999
so as we know the only numbers which have only one non zero digit
[1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 20, ...., 90, 100, 200, ...., 900, 1000, 2000, ...., 9000, 100000, 200000, .........]
so similarly we can directly count

we can also do by precomputing all the numbers in this range
*/