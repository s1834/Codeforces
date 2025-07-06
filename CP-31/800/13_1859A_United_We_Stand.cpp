#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        long long int n;
        cin >> n;

        vector<int> a(n), b, c;
        long long int mx = LLONG_MIN;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if(a[i] > mx) mx = a[i];
        }

        for(int i = 0; i < n; i++) {
            if(a[i] == mx) c.push_back(a[i]);
            else b.push_back(a[i]);
        }

        if(!b.size()) cout << -1 << endl;
        else {
            cout << b.size() << " " << c.size() << endl;
            for(auto x : b) cout << x << " ";
            cout << endl;
            for(auto x : c) cout << x << " ";
            cout << endl;
        }
    }

    return 0;
}

/*
NOTE: use long long int

we need to divide the array 'a' into two parts, such that none elemets of c[j] is not a divisor of any element of b[i]
so we give the biggest element of the array to c and rest to b
*/