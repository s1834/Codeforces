#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        long long n, k;
        cin >> n >> k;

        vector<long long> a(n * k);
        for(long long i = 0; i < n * k; i++) cin >> a[i];

        long long temp = n / 2 + 1, sum = 0, x = temp;
        for(long long i = 0; i < k; i++){
            sum += a[n * k - temp];
            temp += x;
        } 

        cout << sum << endl;
    }

    return 0;
}


/*
it doesnt matter if n * k or n or k is odd or even, we just need to find the sum and to check that and make it simplar we start from end and kepp taking last n / 2 + 1 elements and add that number to sum and keep decreasing that temp by adding x after each iteration until k times.
*/