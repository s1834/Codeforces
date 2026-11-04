#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        
        vector<long long> a(n);
        for (int i = 0; i < n; i++)cin >> a[i];
        
        int maxKeep = 0;
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (a[j] % a[i] == 0) count++;
            }
            maxKeep = max(maxKeep, count);
        }
        
        cout << n - maxKeep << endl;
    }
    
    return 0;
}

/*
Problem: Codeforces B. Rhythmic String

Approach: Brute Force + Divisibility Counting + Greedy

Intuition:
----------
We are given an array a. Each element a[i] makes every position
divisible by a[i] become '1' in an initially zero-filled string.

We need to remove the minimum number of elements so that the
resulting string becomes rhythmic.

A rhythmic string must:
1. Be periodic.
2. Have exactly one '1' among the first p characters, where
   p is its smallest period.

Key Observation:
----------------
Suppose we choose some value x as the period.

For the resulting string to have exactly one '1' in the first
x positions, that '1' must occur at position x.

An array element y sets position y to '1'.

For the string to repeat with period x, every retained element
must be a multiple of x.

Therefore, we can keep all elements divisible by a chosen
array element x.

The best choice is the value that has the maximum number of
array elements divisible by it.

--------------------------------------------------
1. Read Input
--------------------------------------------------

int n;
cin >> n;

vector<long long> a(n);

for (int i = 0; i < n; i++)
    cin >> a[i];

Store all array elements in a.

--------------------------------------------------
2. Initialize the Maximum Number of Elements to Keep
--------------------------------------------------

int maxKeep = 0;

This variable stores the maximum number of elements that
can be retained while satisfying the divisibility condition.

--------------------------------------------------
3. Try Every Element as the Period
--------------------------------------------------

for (int i = 0; i < n; i++) {

    int count = 0;

    for (int j = 0; j < n; j++) {

        if (a[j] % a[i] == 0)
            count++;

    }

    maxKeep = max(maxKeep, count);
}

We consider every array element a[i] as a possible period.

For each candidate:
- Initialize count to zero.
- Traverse the entire array.
- Check whether each element is divisible by a[i].

The condition:

    a[j] % a[i] == 0

means a[j] is a multiple of a[i].

Such elements can be retained together because they
set positions that are multiples of the chosen period.

We count all such elements and update maxKeep.

After checking every candidate, maxKeep contains the
maximum number of elements that can be retained.

--------------------------------------------------
4. Calculate the Minimum Number of Removals
--------------------------------------------------

cout << n - maxKeep << endl;

Initially, there are n elements.

If we can retain maxKeep elements, the minimum number
of removals is:

    removals = n - maxKeep

We print this value for each test case.

--------------------------------------------------
5. Example Walkthrough
--------------------------------------------------

Input:
a = [3, 7, 5, 3]

Try a[0] = 3:

    3 % 3 == 0  -> count = 1
    7 % 3 != 0
    5 % 3 != 0
    3 % 3 == 0  -> count = 2

    maxKeep = 2

Try a[1] = 7:

    Only 7 is divisible by 7.

    count = 1

Try a[2] = 5:

    Only 5 is divisible by 5.

    count = 1

Try a[3] = 3:

    Again, two elements are divisible by 3.

    count = 2

Therefore:

    maxKeep = 2

Minimum removals:

    n - maxKeep = 4 - 2 = 2

Output:
2

We retain [3, 3] and remove [7, 5].

The resulting string is:

    001001001...

It has period 3 and exactly one '1' in its first
three positions.

--------------------------------------------------
6. Complexity Analysis
--------------------------------------------------

Time Complexity: O(n²)

- The outer loop considers every element as a candidate.
- The inner loop checks divisibility against all n elements.

Therefore, there are n * n divisibility checks.

Space Complexity: O(n)

The array a stores n elements.

The remaining variables use O(1) auxiliary space.

Core Idea:
----------
Try every array element as a possible period.

For each candidate a[i], count how many array elements
are divisible by it.

Keep the candidate that allows the maximum number of
elements to remain.

Finally:

    Minimum Removals = n - Maximum Elements Kept
*/