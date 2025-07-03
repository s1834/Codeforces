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
        for(int i = 0; i < n; i++) {
            if(s[i] == '.') {
                if(i + 1 < n && s[i + 1] == '.' && i + 2 < n && s[i + 2] == '.') {
                    three++;
                    break;
                } else single++;
            }
        }
        if(three) cout << 2 << endl;
        else cout << single << endl;
        
    }
    return 0;
}

/* 
1. if three consecutive dots are found, print 2
2. else print the number of single dots

dont overcomplicate by adding multiple if conditions, try to keep it simple
*/