#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    vector<int> v = {1, 2, 3, 4, 5, 5, 4, 3, 2, 1};

    while(t--) {
        char x;
        int ans = 0;
        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < 10; j++) {
                cin >> x;
                if(x == 'X') ans += min(v[i], v[j]); 
            }
        }
        cout << ans << endl;
    }
    return 0;
}

/*
1) create a vector v with the values of the first row of the matrix
2) iterate through the matrix and check if the character is 'X'
3) if it is, add the minimum of the corresponding row and column values from the vector

like for (0, 0) we have v[0] = 1 and v[0] = 1, so we add 1 to the answer
for (0, 1) we have v[0] = 1 and v[1] = 2, so we add 1 to the answer
for (5,5) we have v[5] = 5 and v[5] = 5, so we add 5 to the answer
for (5, 6) we have v[5] = 5 and v[6] = 4, so we add 4 to the answer
for (5, 7) we have v[5] = 5 and v[7] = 3, so we add 3 to the answer
*/