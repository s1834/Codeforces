#include<bits/stdc++.h>
using namespace std;

bool checkSubstring(string x, string s, int n, int m) {
    for (int i = 0; i <= n - m; i++) {
        if (x[i] == s[0]) {
            for(int j = 0; j < m; j++) {
                if(x[i + j] != s[j]) break;
                if(j == m - 1) return true;
            }
        }
    }
    return false;
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, m;
        cin >> n >> m;
        string x, s;
        cin >> x >> s;

        int ops = 0;
        bool found = checkSubstring(x, s, n, m);
        while(ops < 5 && !found) {
            x += x;
            found = checkSubstring(x, s, x.size(), m);
            ops++;
        }

        if (found) cout << ops << endl;
        else cout << -1 << endl;
    }

    return 0;
}

/*
we take ops to only 5 becuase n * m = 25, and even if we take the worst case where n = 1 and m = 25, after 5 operations we will have a string of length 32 which is more than enough to find the substring s in x
n = 1
m = 25
x = "a"
s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
"a" -> "aa" -> "aaaa" -> "aaaaaaaa" -> "aaaaaaaaaaaaaaaa" -> "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
after 5 operations we have a string of length 32 which is more than enough to find the substring s in x
*/