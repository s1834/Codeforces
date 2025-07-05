#include<bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> v(N);
    int ans = INT_MAX;
    for(int i = 0; i < N; i++) {
        cin >> v[i];
        ans = min(ans, abs(v[i]));
    }
    cout << ans << endl;

    return 0;
}

/*
we can do any number or +1 and -1 operations on any of the elements of the array, so we can 𝐴1 × 𝐴2 × 𝐴3 × … × 𝐴𝑁 = 0
so we need to make at least one element zero to achieve this product
thats why we find the minimum absolute value of the elements in the array, so just by doiing that 0 we can make entire product zero
*/