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
        for(int i = 0; i < n; i++) cout << a.size() - a[i] + 1 << " ";
        cout << endl;
    }

    return 0;
}

/*
simply print the "complement" of the number in the array.
like max - current number + 1 
where max is the maximum number in the array.
and we add 1 to avoid 0
*/