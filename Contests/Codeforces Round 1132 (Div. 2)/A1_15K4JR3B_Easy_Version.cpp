#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        
        cout <<  (n / 2) * ((n + 1) / 2) << endl;
    }
    
    return 0;
}

/*
    Codeforces: A1. 15K4JR3B (Easy Version)

    Approach: Mathematical Formula

    Intuition:
    Initially, all three points A, B, and C are located at (0, 0).

    Every operation moves exactly one coordinate of one point by 1
    unit, either positively or negatively.

    We need to maximize the doubled area of triangle ABC after
    performing exactly n operations.

    The maximum doubled area that can be obtained is:

        floor(n / 2) * ceil(n / 2)

    Since integer division is used, this can be calculated as:

        (n / 2) * ((n + 1) / 2)

    Explanation:
    - We can distribute the operations to create two perpendicular
      sides of the triangle.
    - To maximize their product, we distribute the available
      operations as evenly as possible between the two sides.
    - One side gets floor(n / 2) operations.
    - The other side gets ceil(n / 2) operations.

    Since the doubled area of a right triangle is the product
    of its two perpendicular side lengths, the maximum value is
    floor(n / 2) * ceil(n / 2).

    Code Explanation:

    1. Read the number of test cases t.

    2. For each test case:
       - Read n, the exact number of operations.
       - Calculate (n / 2) * ((n + 1) / 2).
       - Print the result.

    Example Walkthrough:

    n = 5

    n / 2       = 2
    (n + 1) / 2 = 3

    Answer = 2 * 3 = 6

    We can achieve this by placing the points at:
        A = (-1, 0)
        B = ( 2, 0)
        C = ( 0, 2)

    The doubled area is:

        |(Bx - Ax)(Cy - Ay) - (By - Ay)(Cx - Ax)|

        = |(2 + 1) * 2|
        = 6

    Complexity Analysis:

    Time Complexity: O(1) per test case.
        Only a constant number of arithmetic operations are performed.

    Space Complexity: O(1).
        Only a few integer variables are used.

    Core Idea:
    Split n as evenly as possible into two integers and multiply
    them to obtain the maximum doubled area:

        Answer = (n / 2) * ((n + 1) / 2)
*/
