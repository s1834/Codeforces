#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        int pos = 0, neg = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if(a[i] == 1) pos++;
            else neg++;
        }

        int ops = 0;
        while(pos < neg || neg % 2) {
            pos++;
            neg--;
            ops++;
        }
        cout << ops << endl;
    }

    return 0;
}

/*
1) calculate the number of 1s and -1s in the array
2) while positive is less than negative or negative is odd, increment positive and decrement negative
so that we can meet the conditions:
i) sum of the array is greater than or equal to 0
ii) product of the array is equal to 1
*/