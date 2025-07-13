#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;
        
        map<char, int> mp;
        for(int i = 0; i < n; i++) mp[s[i]]++;

        k++;
        int odd = 0;
        for(auto x : mp) {
            if(k < 0) break;
            if(x.second % 2) odd++;
        }

        if(k - odd < 0) cout << "NO\n";
        else cout << "YES\n";
    }

    return 0;
}

/*
Take all characters and count their occurrences.
If the count of characters with odd occurrences is less than or equal to k, then it is possible to form a palindrome.
we add 1 in k for the center character in the palindrome.
*/