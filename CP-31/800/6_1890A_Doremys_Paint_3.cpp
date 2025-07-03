#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        map<int, int> mp;
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            mp[x]++;
        }
        
        if(mp.size() == 1) cout << "YES\n";
        else if(mp.size() == 2) {
            int a = 0, b = 0;
            for (auto x : mp) {
                if (a == 0) a = x.second;
                else b = x.second;
            }
            if(a == b - 1 || b == a - 1 || a == b) cout << "YES\n";
            else cout << "NO\n";
        } else cout << "NO\n";
    }
    return 0;
}

/*
1. if only one element is present then the answer is yes.
2. if two elements are present then the answer is yes if the difference between their frequencies is 1 or they are equal. 
3. if more than two elements are present then the answer is no because no matter how we swap, we cannot make sum of all adjacent elements equal.
*/