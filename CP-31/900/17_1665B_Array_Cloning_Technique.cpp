#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        long long int n;
        cin >> n;

        map<long long int, long long int> freq;
        for(int i = 0; i < n; i++) {
            long long int x;
            cin >> x;
            freq[x]++;
        }


        long long int mx = LLONG_MIN;
        for(auto x : freq) mx = max(mx, x.second);

        long long int count = 0;
        while(mx < n) {
            count++;
            if(mx * 2 <= n) {
                count += mx;
                mx *= 2;
            } else {
                count += n - mx;
                mx = n;
            }
        }
        cout << count << endl;
    }

    return 0;
}


/*
We have to do 2 operations:
-> Choose any array and clone it. After that there is one more copy of the chosen array.
-> Swap two elements from any two copies (maybe in the same copy) on any positions.

0 1 3 3 7 0
'0' and '3' both have highest frequency of 2, so they would be best to get minimal operations to swap and get all same numbers in a array.
lets say we are changing the entire array to 3:
0 1 3 3 7 0 -> (1)
0 1 3 3 7 0 -> (2) clone of (1) -----{1}
0 1 3 3 3 3 -> (3) swapped in (1) -----{1 + 2}
0 1 3 3 3 3 -> (4) clone of (3) -----{1 + 2 + 1}
3 3 3 3 3 3 -> (5) swapped in (3) only two '3' were utilized as thats all we needed -----{1 + 2 + 1 + 2 = 6}


So, 
1) we need to find the maximum frequency of any number in the array.
2) if max frequency * 2 <= n, then we can just clone the array and swap the elements to get all same numbers in one array.
3) if max frequency * 2 > n, then we can clone the array and swap only the remaining of n elements to get all same numbers in one array.
*/