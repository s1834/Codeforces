#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) if(a[i] == 1) a[i] = 2;
        for(int i = 0; i < n - 1; i++) if(a[i + 1] %  a[i] == 0) a[i + 1] += 1;
        for(int i = 0; i < n; i++) cout << a[i] << " ";
        cout << endl;
    }

    return 0;
}

/*
first we replace all 1s with 2s, then we iterate through the array and if the next element is divisible by the current one, we increment the next element by 1.
This ensures that no element divides the next one, as we are only incrementing elements when necessary and we are not introducing any new divisibility issues.
*/