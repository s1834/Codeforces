
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        
        string p, q;
        cin >> p >> q;
        
        unordered_map<char, int> mp;
        
        for (char &c : p) mp[c]++;
        
        for (char &c : q) mp[c]--;
        
        string target = "six";
        bool flag = true;

        for (char c : target) {
            if (mp[c] <= 0) {
                flag = false;
                break;
            }
            mp[c]--;
        }

        for (auto it : mp) {
            if (it.second != 0) {
                flag = false;
                break;
            }
        }

        cout << (flag ? "YES\n" : "NO\n");
    }

    return 0;
}

/*
Problem: Codeforces - A. Fraction and Six

Approach: Frequency Counting + Cancellation

Intuition:
----------
We are given two strings:
- p represents the numerator.
- q represents the denominator.

Each character represents a variable.

We can cancel matching variables from the numerator and denominator
because multiplication is commutative.

After performing cancellations, we need:
- The remaining numerator to contain exactly the characters of "six".
- The denominator to contain no remaining characters.

Since the order of variables does not matter, we use a frequency
map to track the count of every character.

The key idea is:
- Increment the frequency for every character in p.
- Decrement the frequency for every character in q.
- Check whether the remaining frequencies can form exactly "six".
- Ensure every frequency becomes zero after removing "six".

--------------------------------------------------
1. Process Multiple Test Cases
--------------------------------------------------

int t;
cin >> t;

while (t--) {

Read the number of test cases and process each test case independently.

--------------------------------------------------
2. Read the Strings
--------------------------------------------------

int n, m;
cin >> n >> m;

string p, q;
cin >> p >> q;

- p represents the numerator.
- q represents the denominator.
- n and m represent their respective lengths.

--------------------------------------------------
3. Build the Frequency Map
--------------------------------------------------

unordered_map<char, int> mp;

The map stores the net frequency of every character.

Process the Numerator:
----------------------

for (char &c : p)
    mp[c]++;

Increment the frequency of every character in p.

A positive frequency means that the character has more occurrences
in the numerator.

Process the Denominator:
------------------------

for (char &c : q)
    mp[c]--;

Decrement the frequency of every character in q.

Matching occurrences from the numerator and denominator cancel
each other automatically.

For example:

p = "sinx"
q = "n"

After processing p:
s = 1
i = 1
n = 1
x = 1

After processing q:
s = 1
i = 1
n = 0
x = 1

The variable n gets cancelled because it appears once in both
the numerator and denominator.

The remaining numerator is "six".

--------------------------------------------------
4. Define the Target String
--------------------------------------------------

string target = "six";
bool flag = true;

target represents the exact expression that must remain in
the numerator after all cancellations.

flag tracks whether the fraction can be simplified to the
required expression.

--------------------------------------------------
5. Check Whether the Remaining Numerator Contains "six"
--------------------------------------------------

for (char c : target) {

Traverse every character of the target string.

if (mp[c] <= 0) {
    flag = false;
    break;
}

Before using a character from the target, check whether its
net frequency is positive.

If mp[c] <= 0, the required character is not available in
sufficient quantity in the numerator.

Therefore, the answer must be NO.

Otherwise:

mp[c]--;

Consume one occurrence of the required character.

After processing all three characters, the frequencies
corresponding to "six" have been removed from the map.

--------------------------------------------------
6. Ensure No Extra Characters Remain
--------------------------------------------------

for (auto it : mp) {
    if (it.second != 0) {
        flag = false;
        break;
    }
}

After removing the required characters of "six", every
remaining frequency must be zero.

Why?

- A positive frequency means extra variables remain in the numerator.
- A negative frequency means some variables remain in the denominator.

Both situations violate the requirement.

Therefore, if any frequency is non-zero, set flag to false.

If all frequencies are zero, the remaining numerator is exactly
"six" and the denominator is empty.

--------------------------------------------------
7. Print the Result
--------------------------------------------------

cout << (flag ? "YES\n" : "NO\n");

If flag is true, print YES.

Otherwise, print NO.

--------------------------------------------------
8. Example Walkthrough
--------------------------------------------------

Example 1:

p = "sinx"
q = "n"

After frequency counting:

s = 1
i = 1
n = 0
x = 1

Target = "six"

Check 's':
mp['s'] = 1, consume it.

Check 'i':
mp['i'] = 1, consume it.

Check 'x':
mp['x'] = 1, consume it.

All remaining frequencies are zero.

Output: YES

Example 2:

p = "xixsms"
q = "mixsxim"

After cancellation, the remaining numerator contains only 's',
while the denominator still contains variables.

The remaining frequencies cannot form exactly "six".

Output: NO

--------------------------------------------------
9. Why the Algorithm Works
--------------------------------------------------

1. Frequency Counting:
   Incrementing numerator characters and decrementing denominator
   characters correctly represents all possible cancellations.

2. Target Verification:
   Checking each character of "six" ensures that the required
   variables are available in the remaining numerator.

3. Extra Character Verification:
   After consuming "six", checking that every frequency is zero
   guarantees that no additional numerator or denominator
   variables remain.

4. Order Independence:
   Since multiplication is commutative, only character frequencies
   matter, not their original positions.

Therefore, the algorithm returns YES exactly when the fraction
can be simplified to "six".

--------------------------------------------------
10. Complexity Analysis
--------------------------------------------------

Let n be the length of p and m be the length of q.

Time Complexity: O(n + m)

- Processing p takes O(n) expected time.
- Processing q takes O(m) expected time.
- Checking the target takes O(1), since "six" has only 3 characters.
- Checking the frequency map takes O(1) expected time because
  there are at most 26 lowercase English letters.

Space Complexity: O(1)

The unordered_map stores at most 26 distinct lowercase characters.

Core Idea:
----------
Use a frequency map to cancel matching characters between the
numerator and denominator. Then consume the characters of "six"
and verify that every remaining frequency is zero.
*/