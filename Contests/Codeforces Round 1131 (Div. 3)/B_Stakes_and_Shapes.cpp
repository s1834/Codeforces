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
Problem: Codeforces - B. Stakes and Shapes

Approach: Greedy + Frequency Counting + Constructive Algorithm

Intuition:
----------
Alice will play:
- Rock exactly r times.
- Scissors exactly s times.
- Paper exactly p times.

Bob must construct a sequence of n = r + s + p moves before
the game starts.

The goal is to ensure that, regardless of the order in which
Alice plays her moves, Bob wins at least as many rounds as Alice.

The key observation is that Bob should use winning moves against
as many of Alice's moves as possible:

- Bob plays Paper to beat Alice's Rock.
- Bob plays Rock to beat Alice's Scissors.
- Bob plays Scissors to beat Alice's Paper.

We first calculate how many guaranteed wins can be obtained
using these winning matchups.

If Bob can guarantee at least ceil(n / 2) wins, the remaining
positions can be filled with arbitrary moves.

Otherwise, we use a fallback construction that still guarantees
the required condition.

--------------------------------------------------
1. Read the Number of Test Cases
--------------------------------------------------

int t;
cin >> t;

Process each test case independently.

--------------------------------------------------
2. Read Alice's Move Frequencies
--------------------------------------------------

int n;
cin >> n;

vector<int> a(n);

long long sum = 0;
bool middleExist = false;

Read Alice's move frequencies into the array a.

The three values represent:
- a[0] = Number of Rock moves.
- a[1] = Number of Scissors moves.
- a[2] = Number of Paper moves.

sum stores the total number of rounds.

For every input value:

sum += a[i];

Since the total number of rounds is the sum of the three
frequencies, sum represents n.

--------------------------------------------------
3. Check Whether a Middle Frequency Is At Least 2
--------------------------------------------------

if (i > 0 && i < n - 1 && a[i] >= 2)
    middleExist = true;

This condition checks whether any middle element of the
frequency array is at least 2.

For the three-element array:
- The first element is excluded.
- The last element is excluded.
- Only the middle element is checked.

Therefore, middleExist becomes true when the second frequency
is at least 2.

--------------------------------------------------
4. Case 1: All Frequencies Are 1
--------------------------------------------------

if (sum == n)
    cout << -1 << endl;

Since there are exactly n elements and their sum is n,
every element must be equal to 1.

In this case, the code outputs -1.

--------------------------------------------------
5. Case 2: Middle Element Is at Least 2
--------------------------------------------------

else if (middleExist)
    cout << sum - 1 << endl;

If the middle frequency is at least 2, the code outputs
sum - 1.

--------------------------------------------------
6. Case 3: All Other Cases
--------------------------------------------------

else
    cout << sum - (n - 1) << endl;

This is the fallback case.

The accompanying comment indicates that all but one element
are equal to 1.

The expression calculates:

sum - (n - 1)

--------------------------------------------------
7. Complexity Analysis
--------------------------------------------------

Time Complexity: O(n) per test case

The algorithm reads the array once and checks each element
during the same traversal.

Space Complexity: O(n)

The vector a stores n elements.

Core Idea:
----------
Calculate the total frequency sum and check whether the middle
frequency is at least 2. Based on these conditions, the code
prints one of three expressions.
*/