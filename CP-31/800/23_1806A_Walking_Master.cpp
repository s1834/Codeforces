#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        if(b > d) cout << -1 << endl;
        else {
            int count = d - b;
            a += count;
            if(a < c) cout << -1 << endl;
            else cout << a - c + count << endl;
        }
    }

    return 0;
}

/*
if YunQian is is standing on point (𝑥,𝑦), she can either move to point (𝑥+1,𝑦+1) or point (𝑥−1,𝑦).

so keeping this in mind, we can say that we can move as much higher as we want in x and y by adding one, but we can only move down in x by subtracting one.

Therefore if b > d, then it is impossible to reach the point (c, d) from (a, b) as we cannot move down in y.
If b <= d, then we can move to (c, d) by adding 1 and store the number of steps in count.
But even after adding count to a, if a < c, then if we move more up, we will again encounter the b decreasing problem, so we return -1.
Otherwise, we can reach the point (c, d) from (a, b)
*/