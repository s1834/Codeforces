#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;

        if ((a + b + c) % 3 != 0) {
            cout << "NO\n";
            continue;
        }
        
        int target = (a + b + c) / 3;
        
        int cnt = 0;
        if (a == target + 1) cnt++;
        if (b == target + 1) cnt++;
        if (c == target + 1) cnt++;
        
        int cnt2 = 0;
        if (a == target - 1) cnt2++;
        if (b == target - 1) cnt2++;
        if (c == target - 1) cnt2++;
        
        cout << (cnt == 1 && cnt2 == 1 ? "YES\n" : "NO\n");
    }

    return 0;
}

/*
    Codeforces: A. Three Piles

    Approach: Mathematical Observation + Counting

    Intuition:
    We need to make all three piles contain the same number of stones
    using exactly one move.

    A move consists of:
        - Taking one stone from one pile.
        - Adding that stone to another pile.

    Since the move does not change the total number of stones, the final
    number of stones in each pile must be equal to the average of the
    original three pile sizes.

    Let:
        total = a + b + c
        target = total / 3

    For all three piles to become equal, the total must be divisible
    by 3.

    Key Observation:
    Since exactly one stone is transferred from one pile to another:
        - The source pile must initially contain target + 1 stones.
        - The destination pile must initially contain target - 1 stones.
        - The third pile must already contain exactly target stones.

    Therefore, we need exactly:
        - One pile with target + 1 stones.
        - One pile with target - 1 stones.
        - One pile with target stones.

    Step-by-Step Explanation:

    1. Check whether the total is divisible by 3:
        if ((a + b + c) % 3 != 0)

       If the total is not divisible by 3, it is impossible to distribute
       the stones equally because the final pile sizes must be integers.

       In this case, print "NO" and move to the next test case.

    2. Calculate the required final number of stones:
        int target = (a + b + c) / 3;

       This is the number of stones each pile must contain after the move.

    3. Count piles containing one extra stone:
        if (a == target + 1) cnt++;
        if (b == target + 1) cnt++;
        if (c == target + 1) cnt++;

       `cnt` represents the number of piles that can act as the source
       of the transfer.

    4. Count piles containing one fewer stone:
        if (a == target - 1) cnt2++;
        if (b == target - 1) cnt2++;
        if (c == target - 1) cnt2++;

       `cnt2` represents the number of piles that can act as the
       destination of the transfer.

    5. Check whether exactly one source and one destination exist:
        cnt == 1 && cnt2 == 1

       If both conditions hold, we can transfer one stone from the
       pile containing target + 1 stones to the pile containing
       target - 1 stones.

       After the transfer, all three piles contain exactly `target`
       stones.

       Otherwise, print "NO".

    Example 1:
        a = 1, b = 2, c = 3

        total = 1 + 2 + 3 = 6
        target = 6 / 3 = 2

        Check the piles:
            a = 1 = target - 1
            b = 2 = target
            c = 3 = target + 1

        cnt = 1
        cnt2 = 1

        Transfer one stone from pile c to pile a:

            [1, 2, 3] -> [2, 2, 2]

        Output: YES

    Example 2:
        a = 2, b = 2, c = 2

        total = 6
        target = 2

        No pile contains target + 1 or target - 1 stones.

        cnt = 0
        cnt2 = 0

        Although all piles are already equal, exactly one move is
        mandatory. Any move will make the piles unequal.

        Output: NO

    Example 3:
        a = 3, b = 4, c = 5

        total = 12
        target = 4

        Pile sizes:
            3 = target - 1
            4 = target
            5 = target + 1

        We can transfer one stone from the third pile to the first:

            [3, 4, 5] -> [4, 4, 4]

        Output: YES

    Complexity Analysis:

    Let t be the number of test cases.

    - Time Complexity: O(1) per test case.
      We perform a constant number of arithmetic operations and
      comparisons for each test case.

      Overall: O(t).

    - Space Complexity: O(1).
      We use only a constant number of variables.

    Core Idea:
    One move can only decrease one pile by 1 and increase another
    pile by 1.

    Therefore, after checking divisibility by 3, we simply need
    exactly one pile with target + 1 stones and exactly one pile
    with target - 1 stones. The third pile must already have
    exactly target stones.
*/