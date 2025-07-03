#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for(int i = 0; i < n; i++)  cin >> a[i];
        if(a[0] == 1) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

/*
if the first element is yes then the answer is yes, otherwise no.
as we can only change from index 2 to n - 1

before what i was doing wrong is i was cheking if it fits in +1 or -1 or currect position as i did a wrong dry run and thought that 2 to n - 1 is to confuse
*/