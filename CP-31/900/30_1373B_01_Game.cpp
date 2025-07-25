#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        string s;
        cin >> s;

        int n = s.size(), one = 0, zero = 0;
        for (int i = 0; i < n; i++) {
            if(s[i] == '1') one++;
            else zero++;
        }

        one = min(one, zero);
        if(one % 2 == 0) cout << "NET\n";
        else cout << "DA\n";
    }

    return 0;
}


/*
Read the question carefully, it says "two different adjacent characters", so we can only remove pairs of '01' or '10'.
we can simply count the number of '1's and '0's in the string, and the minimum of these two counts will give us the number of pairs we can remove.
If this count is even, "NET" wins, otherwise "DA" wins.
*/