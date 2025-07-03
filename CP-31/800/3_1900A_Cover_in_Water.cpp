#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        int three = 0, single = 0;
        for(int i = 1; i < n - 1; i++) {
            if(s[i] == '.') {
                if(s[i - 1] == '.' && s[i + 1] == 
                '.') {
                    three++;
                    break;
                } else single++;
            }
        }
        if(three) cout << 2 << endl;
        else {
            if(s[0] == '.') single++;
            if(s[n - 1] == '.') single++;
            cout << single << endl;
        }
    }
    
    return 0;
}

/* 

*/