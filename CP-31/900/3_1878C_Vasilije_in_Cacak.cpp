#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long n, k, x;
        cin >> n >> k >> x;

        long long mn = k * (k + 1) / 2;
        long long mx = k * (2 * n - k + 1) / 2;

        if (mn <= x && x <= mx)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}

/*

Idea:
------
We need to determine whether it is possible to choose
exactly k distinct integers from the range

[1, n]

such that their sum equals x.

Instead of trying every possible combination, observe
that every valid sum must lie between the minimum and
maximum possible sums.

------------------------------------------------------------

Key Observation:
----------------

Minimum Possible Sum

To obtain the smallest sum,

choose the smallest k distinct numbers.

1 + 2 + ... + k

Using the arithmetic progression formula,

Minimum Sum

= k × (k + 1) / 2

------------------------------------------------------------

Maximum Possible Sum

To obtain the largest sum,

choose the largest k distinct numbers.

n + (n - 1) + ... + (n - k + 1)

Using the arithmetic progression formula,

Maximum Sum

= k × (2 × n - k + 1) / 2

------------------------------------------------------------

If

Minimum Sum ≤ x ≤ Maximum Sum

then a valid selection always exists.

Otherwise,

it is impossible.

------------------------------------------------------------

Why Does This Work?
-------------------

Suppose

n = 5

k = 3

Possible selections are

{1,2,3} → 6

{1,2,4} → 7

{1,2,5} → 8

{1,3,4} → 8

{2,3,4} → 9

{1,3,5} → 9

{1,4,5} → 10

{2,3,5} → 10

{2,4,5} → 11

{3,4,5} → 12

Notice that every integer between

6

and

12

can be obtained.

In general,

for distinct numbers chosen from a consecutive range,

every value between the minimum and maximum possible
sum is achievable.

Therefore,

checking only the range is sufficient.

------------------------------------------------------------

Algorithm:
----------

For each test case,

1.

Compute

Minimum Sum

= k × (k + 1) / 2

2.

Compute

Maximum Sum

= k × (2 × n - k + 1) / 2

3.

If

Minimum Sum ≤ x ≤ Maximum Sum

print

"YES"

otherwise

print

"NO".

------------------------------------------------------------

Example:
--------

Input

n = 5

k = 3

x = 10

Minimum Sum

1 + 2 + 3 = 6

Maximum Sum

3 + 4 + 5 = 12

Since

6 ≤ 10 ≤ 12

Answer

YES

------------------------------------------------------------

Example:

n = 5

k = 3

x = 3

Minimum Sum

6

Since

3 < 6

it is impossible.

Answer

NO

------------------------------------------------------------

Time Complexity:
----------------

O(1)

Only a few arithmetic operations are performed for each
test case.

------------------------------------------------------------

Space Complexity:
-----------------

O(1)

Only a constant amount of extra space is used.

*/