#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int l, r;
        cin >> l >> r;
        
        if(l == r) cout << 0 << endl;
        else if(l >= 0 || r <= 0) {
            if(l == 0 || r == 0) cout << r - l - 1 << endl;
            else cout << r - l << endl;
        }
        else {
            int x = abs(l);
            int y = abs(r);
            
            int diff = abs(x - y);
            if(diff <= 1) cout << 0 << endl;
            else cout << diff - 1 << endl;
        }
    }
    
    return 0;
}

/*
Problem: Codeforces A. Numbers on the Board

Approach: Mathematical Observation + Case Analysis

Intuition:
----------
All integers from l to r are initially present on the board.

A number x is beautiful if it is equal to the sum of all
numbers currently remaining on the board.

We can erase numbers, but at least one number must remain.

The key observation is that we only need to consider three
cases based on the position of the interval relative to zero:

1. The interval contains only one number.
2. The interval lies entirely on one side of zero or touches zero.
3. The interval contains both negative and positive numbers.

--------------------------------------------------
1. Read the Input
--------------------------------------------------

int t;
cin >> t;

Process each test case independently.

For every test case:

int l, r;
cin >> l >> r;

l and r represent the inclusive boundaries of the interval.

--------------------------------------------------
2. Case 1: Only One Number Exists
--------------------------------------------------

if(l == r) cout << 0 << endl;

If l == r, the board contains exactly one number.

The sum of all numbers is that number itself.

Therefore, it is already beautiful, and no erasures
are required.

--------------------------------------------------
3. Case 2: Interval Lies on One Side of Zero
--------------------------------------------------

else if(l >= 0 || r <= 0)

This condition handles intervals where all numbers are
non-negative or all numbers are non-positive.

There are two subcases.

A. Interval Contains Zero
-------------------------

if(l == 0 || r == 0)
    cout << r - l - 1 << endl;

If zero is present, we can keep zero along with one
additional number.

For example:

    [0, 4]

Keep:

    [0, 4]

Their sum is 4, so 4 is beautiful.

The number of elements initially present is:

    r - l + 1

We keep two elements, so the number of erasures is:

    (r - l + 1) - 2
    = r - l - 1

B. Interval Does Not Contain Zero
---------------------------------

else cout << r - l << endl;

When all numbers are strictly positive or strictly negative,
we can keep only one number.

A single remaining number is always equal to the sum
of all remaining numbers.

Initially, there are:

    r - l + 1

numbers.

After keeping one number, the number of erasures is:

    (r - l + 1) - 1
    = r - l

--------------------------------------------------
4. Case 3: Interval Contains Both Negative and Positive
--------------------------------------------------

else {

    int x = abs(l);
    int y = abs(r);

    int diff = abs(x - y);

}

This case occurs when:

    l < 0 && r > 0

The interval contains negative numbers, zero, and
positive numbers.

We calculate:

    x = |l|
    y = |r|

These represent the magnitudes of the negative and
positive boundaries.

Their absolute difference is:

    diff = ||l| - |r||

This measures how unbalanced the interval is around zero.

--------------------------------------------------
5. Check the Difference
--------------------------------------------------

if(diff <= 1)
    cout << 0 << endl;

If the difference between the magnitudes is at most 1,
the interval is balanced around zero.

The sum of all numbers in the interval is either 0
or one of the existing boundary values.

Therefore, at least one beautiful number already exists,
and no erasures are required.

Otherwise:

    cout << diff - 1 << endl;

When the difference is greater than 1, the code calculates
the minimum number of erasures using:

    diff - 1

--------------------------------------------------
6. Example Walkthrough
--------------------------------------------------

Example 1:

    l = -2, r = 2

    x = abs(-2) = 2
    y = abs(2) = 2

    diff = abs(2 - 2) = 0

Since diff <= 1:

    Answer = 0

The sum of all numbers is:

    -2 + (-1) + 0 + 1 + 2 = 0

Therefore, zero is already beautiful.

Example 2:

    l = -2, r = 5

    x = 2
    y = 5

    diff = abs(2 - 5) = 3

Since diff > 1:

    Answer = diff - 1
           = 3 - 1
           = 2

We erase 4 and 5.

The remaining numbers are:

    [-2, -1, 0, 1, 2, 3]

Their sum is 3, so 3 is beautiful.

--------------------------------------------------
7. Complexity Analysis
--------------------------------------------------

Time Complexity: O(1) per test case

Only a few comparisons and arithmetic operations
are performed.

Space Complexity: O(1)

Only a constant number of variables are used.

Core Idea:
----------
Handle the interval based on its relationship with zero:

1. If l == r, no erasures are needed.
2. If the interval lies on one side of zero:
   - If zero is included, erase r - l - 1 elements.
   - Otherwise, erase r - l elements.
3. If the interval contains both negative and positive
   numbers:
   - Calculate diff = ||l| - |r||.
   - If diff <= 1, answer is 0.
   - Otherwise, answer is diff - 1.

This gives the required minimum number of erasures
using constant-time calculations.
*/