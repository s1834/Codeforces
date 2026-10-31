#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        
        vector<long long> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        
        sort(a.begin(), a.end());
        
        long long cost = 0;
        long long operations = 0;
        
        for (int i = 0; i < n - 1; i++) {
            long long diff = a[i + 1] - a[i];
            
            cost += diff * min(i + 1, n - i - 1); // min of elements on left and elements on right
            operations += diff;
        }
        
        cout << cost << " " << operations << '\n';
    }

    return 0;
}

/*
Problem: D. Lock and Unlock

Approach: Sorting + Greedy + Difference Contribution

Intuition:
----------
We need to make all array elements equal using operations that
increase or decrease every unlocked element by 1.

In each operation:
- Exactly k elements are locked.
- Every unlocked element changes by either +1 or -1.
- The operation cost is k.

The objective is to minimize:
1. Total cost.
2. Number of operations among all minimum-cost solutions.

The key observation is that sorting the array allows us to
calculate the minimum cost using the differences between
consecutive elements.

--------------------------------------------------
1. Read Input and Sort the Array
--------------------------------------------------

int n;
cin >> n;

vector<long long> a(n);

for (int i = 0; i < n; i++)
    cin >> a[i];

sort(a.begin(), a.end());

Sorting places the elements in non-decreasing order.

This makes the differences between consecutive elements
non-negative and allows us to process the array from left
to right.

--------------------------------------------------
2. Initialize the Answers
--------------------------------------------------

long long cost = 0;
long long operations = 0;

cost stores the minimum total cost.

operations stores the minimum number of operations among
the optimal solutions.

--------------------------------------------------
3. Process Consecutive Differences
--------------------------------------------------

for (int i = 0; i < n - 1; i++) {

    long long diff = a[i + 1] - a[i];

    Since the array is sorted, diff represents the gap
    between two consecutive elements.

    To make all elements equal, this gap must be bridged
    through operations that change one side relative to
    the other.

    The number of elements on the left side is:

        i + 1

    The number of elements on the right side is:

        n - i - 1

    The smaller of these two groups determines the minimum
    cost contribution for each unit of difference.

    cost += diff * min(i + 1, n - i - 1);

    Therefore, the contribution of this gap to the total
    minimum cost is:

        diff * min(left_count, right_count)

    We also add the gap itself to the operation count:

        operations += diff;

    This is because each unit of difference requires one
    operation in the optimal construction.

}

--------------------------------------------------
4. Print the Result
--------------------------------------------------

cout << cost << " " << operations << '\n';

The first value is the minimum total cost.

The second value is the minimum number of operations needed
to achieve that minimum cost.

--------------------------------------------------
5. Example Walkthrough
--------------------------------------------------

Input:
n = 3
a = [1, 2, 3]

After sorting:
a = [1, 2, 3]

Initially:
cost = 0
operations = 0

For i = 0:
    diff = 2 - 1 = 1
    left_count = 1
    right_count = 2

    cost += 1 * min(1, 2) = 1
    operations += 1

For i = 1:
    diff = 3 - 2 = 1
    left_count = 2
    right_count = 1

    cost += 1 * min(2, 1) = 1
    operations += 1

Final result:
    cost = 2
    operations = 2

Output:
2 2

--------------------------------------------------
6. Complexity Analysis
--------------------------------------------------

Sorting:
    O(n log n)

Traversing consecutive differences:
    O(n)

Total Time Complexity:
    O(n log n) per test case.

Space Complexity:
    O(n) for storing the array.
    The calculation itself uses O(1) extra space.

Core Idea:
----------
After sorting, consider every gap between consecutive
elements independently.

For each gap:
- Multiply its size by the smaller number of elements
  on either side to obtain its cost contribution.
- Add the gap to the total number of operations.

Summing these contributions gives the two required answers.
*/