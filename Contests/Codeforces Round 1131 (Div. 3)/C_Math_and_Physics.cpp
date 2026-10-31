#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        
        vector<int> a(n);
        long long sum = 0;
        bool middleExist = false;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];

            // if middle has a number greater than 2
            if (i > 0 && i < n - 1 && a[i] >= 2) middleExist = true;
        }

        if (sum == n) cout << -1 << endl;
        else if (middleExist) cout << sum - 1 << endl;
        else cout << sum - (n - 1) << endl; // all except 1 element are == 1
    }

    return 0;
}

/*
Problem: C. Math and Physics

Approach: Greedy Observation

Intuition:
----------
We are given n cores with initial masses stored in array a.

In one operation:
- We choose a core whose mass is at least 2.
- Split its mass into two positive parts x and y.
- Remove the selected core.
- Add x to its left neighbor, if one exists.
- Add y to its right neighbor, if one exists.
- Any part assigned to a nonexistent neighbor is lost.

The goal is to reduce the sequence to exactly one core and
maximize its final mass.

--------------------------------------------------
1. Read Input and Calculate Total Mass
--------------------------------------------------

int n;
cin >> n;

vector<int> a(n);
long long sum = 0;

While reading the array, calculate the total initial mass:

sum += a[i];

Since every operation only redistributes mass between
neighboring cores or loses mass at the boundaries, the
final mass can never exceed the initial total sum.

--------------------------------------------------
2. Check Whether a Middle Core Has Mass At Least 2
--------------------------------------------------

bool middleExist = false;

if (i > 0 && i < n - 1 && a[i] >= 2)
    middleExist = true;

This checks whether any core strictly between the first
and last positions initially has mass at least 2.

Such a core can be split, allowing its mass to be
distributed to both neighboring cores.

--------------------------------------------------
3. Case 1: Every Core Has Mass 1
--------------------------------------------------

if (sum == n)
    cout << -1 << endl;

Since every mass is a positive integer, sum == n means
all n cores have mass exactly 1.

No operation is possible because an operation requires
a core with mass at least 2.

Therefore, we cannot reduce the sequence to one core
when n >= 2, so the answer is -1.

--------------------------------------------------
4. Case 2: A Middle Core Has Mass At Least 2
--------------------------------------------------

else if (middleExist)
    cout << sum - 1 << endl;

If an internal core has mass at least 2, the code outputs
the total initial mass minus 1.

The idea is that an internal core can distribute mass
to both sides, helping combine the sequence while losing
as little mass as possible at the boundaries.

--------------------------------------------------
5. Case 3: No Middle Core Has Mass At Least 2
--------------------------------------------------

else
    cout << sum - (n - 1) << endl;

Here, every internal core initially has mass 1.

Since sum != n, at least one of the two boundary cores
must have mass greater than 1.

The code outputs:

sum - (n - 1)

This subtracts the contribution of the n - 1 cores
that have mass 1.

--------------------------------------------------
6. Complexity Analysis
--------------------------------------------------

Time Complexity: O(n) per test case

We traverse the array once to calculate the sum and
check whether an internal element is at least 2.

Space Complexity: O(n)

The array a stores all n initial masses.

Core Idea:
----------
The solution uses the total initial mass and checks
whether an internal core has mass at least 2.

Based on these observations, it prints one of three
possible answers:
- -1, if all masses are 1.
- sum - 1, if an internal mass is at least 2.
- sum - (n - 1), otherwise.
*/