#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        int flag = 0;
        for (int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(__gcd(a[i], a[j]) <= 2) {
                    flag = 1;
                    break;
                }
            }
        }
        if(flag) cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
}

/*
we need to if array of positive integers 'a' is good, it is good iff:
1) the greatest common divisor of all elements in a is no more than its length
2) for any prefixes of length >= 2 are good

so we can say by tis that:
If you find any 2 numbers with gcd <= 2, then the answer is Yes else answer is No.
we check for 2 numbers because that is the minimum prefix length we can have
and if length is 2 than its gcd cannot exceed 2.
so if we find such numbers so automatically all prefixes will be good after this as we can reorder and make this two elements first as the more number we keep on taking, the lower gcd goes.
*/