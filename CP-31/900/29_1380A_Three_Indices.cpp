#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> p(n);
        for(int i = 0; i < n; i++) cin >> p[i];

        int flag = 1;
        for(int i = 1; i < n - 1; i++) {
            if(p[i] > p[i - 1] && p[i] > p[i + 1]) {
                cout << "YES\n" << i << " " << i + 1 << " " << i + 2 << endl;
                flag = 0;
                break;
            }
        }
        if(flag) cout << "NO\n";
    }

    return 0;
}


/*
If we find an index 'i' for which
p[i] > p[i - 1] 
p[i] > p[i + 1]
then we can return "YES" with the indices i, i + 1, and i + 2.
else we return "NO".
*/