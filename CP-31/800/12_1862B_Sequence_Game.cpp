#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> b(n), a;
        for(int i = 0; i < n; i++) cin >> b[i];
        
        a.push_back(b[0]);
        for(int i = 1; i < n; i++) {
            if(b[i - 1] <= b[i]) a.push_back(b[i]);
            else {
                a.push_back(b[i]);
                a.push_back(b[i]);
            }
        }

        cout << a.size() << endl;
        for(auto x : a) cout << x << " ";
        cout << endl;
    }

    return 0;
}

/*
1) every b[i], if has been jotted from 'a', must be greater or equealt to the previous number in 'a'
2) so form b[i], we directly write b[i] if b[i] >= b[i - 1]
3) else if b[i] < b[i - 1], we write b[i] twice, as we need to make sure that the next number in 'a' is greater than or equal to b[i]

b = {4, 4, 6, 3}
a = {4, 4, 6, 3, ...., 3}
a = {4, 4, 6, 3, 3}
we could have made it like {4, 3, 2, 1, 4, ...., 6, ...., 3, .....} but when the condition is already satified, why bother
*/