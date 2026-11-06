#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        
        vector<int> a(n);
        long long total = 0;
        
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            total += (long long)pow(2, a[i]);
        }
        
        sort(a.begin(), a.end(), greater<int>());
        
        long long target = total / 2;
        long long sum = 0;
        
        for(int i = 0; i < n; i++) {
            long long val = (long long)pow(2, a[i]);
            if(sum + val <= target)  sum += val;
        }
        
        cout << sum * (total - sum) << endl;
    }

    return 0;
}

/*
    Codeforces: A2. 15K4JR3B (Hard Version)

    Approach: Greedy + Sorting + Partitioning the Total Sum

    Intuition:
    In each operation, we can add or subtract 2^a[i] to exactly one
    coordinate of one of the three points.

    Let w[i] = 2^a[i].

    The key observation is that we can construct two perpendicular
    sides of the triangle using two groups of operations.

    If the total sum of all weights is S, and one group has sum X,
    the other group has sum S - X.

    The maximum doubled area is therefore:

        X * (S - X)

    To maximize this product, we want X and S - X to be as close
    as possible. Ideally, both should be S / 2.

    This becomes a partitioning problem: divide the available
    powers of two into two groups whose sums are as balanced
    as possible.

    Variables:
    - t:
        Number of test cases.

    - n:
        Number of operations.

    - a:
        Stores the exponents of the powers of two.

    - total:
        Sum of all operation lengths:

            total = sum(2^a[i])

    - target:
        Half of the total sum. This is the ideal sum for one group.

    - sum:
        Stores the sum of the selected operation lengths for the
        first group.

    Step-by-Step Explanation:

    1. Read the number of test cases.

    2. For each test case:
       - Read n.
       - Initialize total = 0.
       - Read all exponents into array a.
       - Calculate the corresponding power of two and add it to total.

            total += 2^a[i]

       This gives the total available movement length.

    3. Sort the exponents in descending order:

            sort(a.begin(), a.end(), greater<int>());

       This processes larger powers of two first.

    4. Calculate the target:

            target = total / 2;

       We want to select a group whose sum is as close as possible
       to half of the total.

    5. Greedily construct the first group:

       For every exponent:
       - Calculate its corresponding power of two.
       - Check whether adding it keeps the current sum within target.
       - If yes, include it in the group.

            if(sum + val <= target)
                sum += val;

       This builds one partition without exceeding the target.

    6. Calculate the answer:

            sum * (total - sum)

       The first group has total movement sum, while the second
       group has total - sum.

       Their product gives the doubled area.

    Example Walkthrough:

    n = 6
    a = [0, 1, 2, 2, 4, 0]

    Corresponding powers of two:

        [1, 2, 4, 4, 16, 1]

    Total:

        total = 1 + 2 + 4 + 4 + 16 + 1
              = 28

    After sorting exponents in descending order:

        a = [4, 2, 2, 1, 0, 0]

    Corresponding values:

        [16, 4, 4, 2, 1, 1]

    Target:

        target = 28 / 2 = 14

    Greedy selection:

        sum = 0

        16: 0 + 16 > 14, skip.
         4: 0 + 4 <= 14, include. sum = 4
         4: 4 + 4 <= 14, include. sum = 8
         2: 8 + 2 <= 14, include. sum = 10
         1: 10 + 1 <= 14, include. sum = 11
         1: 11 + 1 <= 14, include. sum = 12

    Final partition sums:

        First group  = 12
        Second group = 28 - 12 = 16

    Answer:

        12 * 16 = 192

    Complexity Analysis:

    Time Complexity: O(n log n) per test case.
        - Reading and calculating the total: O(n).
        - Sorting the array: O(n log n).
        - Greedy partitioning: O(n).

    Space Complexity: O(n).
        The array a stores n exponents.

    Core Idea:
    Convert every operation into its corresponding power-of-two
    movement length, sort the values in descending order, greedily
    build one group without exceeding half the total, and multiply
    the two resulting group sums.

    Implementation Note:
    The code uses pow(2, a[i]) and converts the result to long long.
    Since all exponents are small (0 to 24), these values are exactly
    representable as integers in this problem's constraints.
*/