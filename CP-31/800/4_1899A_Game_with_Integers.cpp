#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;

        if((n + 1) % 3 == 0 || (n - 1) % 3 == 0) cout << "First\n";
        else cout << "Second\n";
    }
    return 0;
}

/* 
if n + 1 or n - 1 is not divisible by 3 then the second player can always win by +1 or -1
*/