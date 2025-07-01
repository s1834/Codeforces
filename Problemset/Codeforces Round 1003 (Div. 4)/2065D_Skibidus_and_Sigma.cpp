#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> v;
        for (int i = 0; i < n; i++) {
            int x;
            vector<int> temp;
            for(int j = 0; j < m; j++) {
                cin >> x;
                temp.push_back(x);
            }
            v.push_back(temp);
        }

        vector<vector<int>> sum;
        for(int i = 0; i < n; i++) {
            vector<int> prefixSum;
            prefixSum.push_back(v[i][0]);
            for(int j = 1; j < m; j++) {
               prefixSum.push_back(prefixSum[j - 1] + v[i][j]);
            }
            
            int tempSum = 0;
            for (auto x : prefixSum) tempSum += x;
            
            sum.push_back({tempSum, i});
        }
        
        int score = 0;
        n = m * n;
        for(auto x : sum) {
            for(int i = 0; i < m; i++) {
                score += v[x[1]][i] * n;
                n--;
            }
        }

        cout << score << endl;
    }

    return 0;
}