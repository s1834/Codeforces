#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        
        string s;
        cin >> s;
        
        char curr = 'R';
        int count = 0;
        for(int i = 0; i < n; i++) {
            if(curr != s[i]) {
                count++;
                curr = (curr == 'R') ? 'B' : 'R';
            }
            
            curr = (curr == 'R') ? 'B' : 'R';
        }
        
        cout << count << endl;
    }
    
    return 0;
}

/*
    Codeforces: B. Stubborn Pen

    Approach: Greedy Simulation

    Intuition:
    The pen initially writes in red ('R').

    After writing every letter, its color automatically switches:
        - Red -> Blue
        - Blue -> Red

    Before writing each letter, we can also manually switch the color
    if the current color does not match the required character.

    To minimize manual switches, we should manually switch the pen
    only when its current color differs from the required character.

    After ensuring the correct color, we write the letter and let the
    pen switch automatically for the next position.

    Variables:
        curr  -> Current color of the pen before writing the current letter.
        count -> Total number of manual switches performed.

    Step-by-Step Explanation:

    1. Initialize:
        char curr = 'R';
        int count = 0;

       The pen initially writes in red, and no manual switches have
       been performed.

    2. Traverse the string:
        for(int i = 0; i < n; i++)

       Process each character from left to right.

    3. Check whether a manual switch is required:
        if(curr != s[i])

       If the current pen color does not match the required color:
           - Increment the manual switch count.
           - Switch the current color manually.

        count++;
        curr = (curr == 'R') ? 'B' : 'R';

       After this operation, `curr` matches `s[i]`, so the current
       character can be written correctly.

    4. Perform the automatic switch:
        curr = (curr == 'R') ? 'B' : 'R';

       After writing the current character, the pen automatically
       changes its color.

       This prepares the pen for the next character.

    5. Print the answer:
        cout << count << endl;

       After processing all characters, `count` contains the minimum
       number of manual switches required.

    Example:
        n = 5
        s = "BRRBR"

        Initially:
            curr = 'R'
            count = 0

        i = 0, s[i] = 'B'

            Current color = 'R'
            Required color = 'B'

            Manual switch: R -> B
            count = 1

            Write 'B'.
            Automatic switch: B -> R

        i = 1, s[i] = 'R'

            Current color = 'R'
            Required color = 'R'

            No manual switch required.

            Write 'R'.
            Automatic switch: R -> B

        i = 2, s[i] = 'R'

            Current color = 'B'
            Required color = 'R'

            Manual switch: B -> R
            count = 2

            Write 'R'.
            Automatic switch: R -> B

        i = 3, s[i] = 'B'

            Current color = 'B'
            Required color = 'B'

            No manual switch required.

            Write 'B'.
            Automatic switch: B -> R

        i = 4, s[i] = 'R'

            Current color = 'R'
            Required color = 'R'

            No manual switch required.

            Write 'R'.
            Automatic switch: R -> B

        Final count = 2

        Output: 2

    Why Greedy Works:
    Before writing each character, there are only two possible colors.

    - If the current color already matches the required character,
      a manual switch is unnecessary.
    - If the colors differ, a manual switch is unavoidable because
      the character must be written in its required color.

    Therefore, switching manually exactly when the colors differ
    is optimal at every position.

    Complexity Analysis:

    Let n be the length of the string.

    - Time Complexity: O(n)
      We traverse the string exactly once and perform constant-time
      operations for each character.

    - Space Complexity: O(1)
      We use only two additional variables: `curr` and `count`.

    Core Idea:
    Simulate the pen's color while traversing the string.

    Manually switch only when the current color does not match the
    required character, then perform the automatic switch after
    writing each character.
*/