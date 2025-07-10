#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int x, k;
        cin >> x >> k;

        vector<int> ans;
        int temp = x;
        while(x) {
            if(temp % k == 0) {
                temp--;
                continue;
            }
            ans.push_back(temp);
            x -= temp;
            temp = x;
        }
        cout << ans.size() << endl;
        for(int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
        cout << endl;
    }

    return 0;
}

/*
we simply start decreaing x by the max number which is leass than or equal to x and not divisible by k.
We keep doing this until x becomes 0.
*/