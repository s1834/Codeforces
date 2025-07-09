#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, k, x;
        cin >> n >> k >> x;

        if(n < x) cout << "NO\n";
        else if(n == x) {
            cout << "YES\n";
            cout << x << endl;
        }
        else {
            vector<int> a;
            if(k > n) k = n;
            while(n >= k && k > 0) {
                a.push_back(k);
                n -= k;
                while(k > n && k > 0) k--;
                if(k == x) k--;
            }
            if(n != 0) cout << "NO\n";
            else {
                cout << "YES\n";
                cout << a.size() << endl;
                for(int i = 0; i < a.size(); i++) cout << a[i] << " ";
                cout << endl;
            }
        }
    }
    
    return 0;
}

/*

*/