#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        long long int n;
        cin >> n;

        long long int three = 0, two = 0;
        while(n > 0 && n % 3 == 0) {
            n /= 3;
            three++;
        }

        while(n > 0 && n % 2 == 0) {
            n /= 2;
            two++;
        }

        if(n > 1 || two > three) cout << -1 << endl;
        else cout << three + (three - two) << endl;
    }

    return 0;
}


/*
n / 6 -> factor of 6
6 = 2 * 3

n = p1^a1 * p2^a2 * ... * pk^ak
-> add a prime factor of 2 in op1
-> remove a prime factor of 2 & 3 in op2
n = 2^a * 3^b

if n has any other prime factor other than 2 or 3, then we cannot make it 1, so return -1
if a > b, then we have a extra 2s, which we can remove by multiplying by 2, so return -1

if a <= b, then we have a extra 3s, which we can remove by multiplying by 2 and doing op2 to remove their pair
(b - a) + b
(b - a) -> op1 the number of times we need to multiply by 2 to make the number of 2s equal to the number of 3s
b -> op2 the number of times we need to remove a pair of 2 and 3 to make the number 1
*/