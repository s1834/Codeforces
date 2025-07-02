#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n, x;
        cin >> n >> x;

        int arr[n + 2];
        arr[0] = 0;
        for(int i = 0; i < n; i++) cin >> arr[i + 1];

        int mx = 0;
        arr[n + 1] = x;
        n += 2;
        for(int i = 1; i < n; i++) {
            if(i == n - 1) mx = max(mx, 2 * (arr[i] - arr[i - 1]));
            else mx = max(mx, arr[i] - arr[i - 1]);
        }
        cout << mx << endl;
    }

    return 0;
}

/* 
1. add 0 at the start and x at the end of the array
2. find the maximum distance between two consecutive elements in the array
3. if the last element is not the maximum, then double the distance between the last two elements to account for the circular nature of the problem

dont make silly mistaked, read the problem and code carefully
*/