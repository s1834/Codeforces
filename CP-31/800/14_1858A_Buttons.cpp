#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int a, b, c;
        cin >> a >> b >> c;

        a += ceil(c / 2.0);
        c -= ceil(c / 2.0);
        b += c;
        if(a > b) cout << "First\n";
        else cout << "Second\n";
    }

    return 0;
}

/*
'c' can be divided into two parts, one for 'a' and one for 'b'
so we give half of 'c' to 'a' and the other half to 'b'
if its odd we give the extra one to 'a'
then if and only if 'a' is greater than 'b', we return "First" else "Second"
if they are equal then also second will play last and win
*/