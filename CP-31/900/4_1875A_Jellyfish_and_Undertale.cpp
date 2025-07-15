#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        long long int a, b, n;
        cin >> a >> b >> n;

        vector<long long int> x(n);
        for(int i = 0; i < n; i++) cin >> x[i];

        long long int count = b;
        for(int i = 0; i < n; i++) count += min(x[i], a - 1);

        cout << count << endl;
    }

    return 0;
}


/*

*/