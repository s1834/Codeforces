#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        
        vector<int> a(n);
        int two = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(a[i] == 2) two++;
        }

        int temp = 0;
        int k = -1;
        for(int i = 0; i < n; i++) {
            if(a[i] == 2) temp++;
            if(temp == two - temp) {
                k = i + 1;
                break;
            }
        }

        cout << k << endl;
    }

    return 0;
}

/*
To find such a k, we just need to check if we have even number of 2's in the array so we can divide them equally.
if it is one, we can directly get the answer when we check for temp == two - temp.

also always try to make it simplar like here it is addition, whereas in your previous code it was multiplication, so it caused runtime error of signed integer overflow.
*/