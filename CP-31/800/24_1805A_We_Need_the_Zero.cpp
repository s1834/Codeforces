#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        long long totalXOR = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            totalXOR ^= a[i];
        }
        
        if(n % 2) cout << totalXOR << endl;
        else {
            if(totalXOR) cout << -1 << endl;
            else cout << totalXOR << endl;
        }
    }

    return 0;
}

/*
XOR:
a b a^=b
0 0  0
1 0  1
0 1  1
1 1  0

Properties:
1) a ⊕ a = 0
2) a ⊕ 0 = a
3) a ⊕ b ⊕ c = a ⊕ c ⊕ b

E = a1 ⊕ x ⊕ a2 ⊕ x ⊕ .... ⊕ an ⊕ x
E = a1 ⊕ a2 ⊕ .... ⊕ an ⊕ x ⊕ x .... ⊕ x

Case 1: n is even
E = a1 ⊕ a2 ⊕ .... ⊕ an
lets say if n is even, N = 6
E = a1 ⊕ a2 ⊕ a3 ⊕ a4 ⊕ a5 ⊕ a6 ⊕ x ⊕ x ⊕ x ⊕ x ⊕ x ⊕ x
                                  |___|   |___|   |___|
                                    0       0       0    (by property 1)
E = a1 ⊕ a2 ⊕ a3 ⊕ a4 ⊕ a5 ⊕ a6
then the answer completely depends on the XOR of all elements.
if XOR of all elements is 0, then we can make it 0 by taking any random value of x.
if XOR of all elements is not 0, then we cannot make it 0, so we return -1.

Case 2: n is odd
E = a1 ⊕ a2 ⊕ .... ⊕ an ⊕ x
lets say if n is odd, N = 5
x = a1 ⊕ a2 ⊕ a3 ⊕ a4 ⊕ a5
if we take xor of all elements that means when they are XORed with themselves, again by property 1, they will become 0.
so if it is odd, we can always make it 0 by taking x as XOR of all elements.
*/