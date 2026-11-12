
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        
        vector<int> h(n);
        for (int i = 0; i < n; i++) cin >> h[i];
        
        sort(h.begin(), h.end());
        
        vector<int> left, right, middle;
        
        for (int i = 0; i < n;) {
            int j = i;
            while (j < n && h[j] == h[i]) j++;
            
            int freq = j - i;
            
            left.push_back(h[i]);
            
            if (freq >= 2) right.push_back(h[i]);
            
            for (int k = 2; k < freq; k++) middle.push_back(h[i]);
            
            i = j;
        }
        
        if (right.empty()) {
            right.push_back(left.back());
            left.pop_back();
        }
        
        vector<int> ans;
        for (int x : left) ans.push_back(x);
        for (int x : middle) ans.push_back(x);
        
        reverse(right.begin(), right.end());
        for (int x : right) ans.push_back(x);
        
        cout << left.size() + right.size() << "\n";
        
        for (int x : ans) cout << x << " ";
        cout << endl;
    }

    return 0;
}

/*
    Codeforces: C. Books on a Shelf

    Approach: Sorting + Frequency Counting + Greedy Construction

    Intuition:
    A book is visible from the left if its height is strictly greater
    than every book before it.

    Similarly, a book is visible from the right if its height is
    strictly greater than every book after it.

    We need to arrange the books to maximize the number of books
    visible from at least one side.

    The key observation is that:
        - We can make one occurrence of every distinct height visible
          from the left.
        - If a height occurs at least twice, we can make another
          occurrence visible from the right.
        - Any additional occurrences of the same height cannot be
          visible from either side because visibility requires a
          strictly greater height.

    Therefore, we group equal heights and construct the arrangement
    using three groups:
        1. `left`: One occurrence of every distinct height.
        2. `right`: One additional occurrence of every height that
           appears at least twice.
        3. `middle`: All remaining duplicate occurrences.

    Variables:
        h      -> Original array of book heights.
        left   -> Books selected to be visible from the left.
        right  -> Books selected to be visible from the right.
        middle -> Remaining books that will not be visible.
        ans    -> Final arrangement of all books.

    Step-by-Step Explanation:

    1. Sort the heights:
        sort(h.begin(), h.end());

       Sorting places equal heights together, making it easy to
       calculate the frequency of every distinct height.

    2. Process each group of equal heights:

        for (int i = 0; i < n;) {
            int j = i;

            while (j < n && h[j] == h[i]) j++;

            int freq = j - i;

       Here:
           - `i` is the starting index of the current group.
           - `j` is the first index after the current group.
           - `freq` is the number of occurrences of the current height.

       Since the array is sorted, all occurrences of a particular
       height are consecutive.

    3. Select one occurrence for the left group:
        left.push_back(h[i]);

       We place one copy of every distinct height in `left`.

       Since these heights are processed in increasing order, every
       selected book will be strictly taller than all previously
       selected books when placed in the final arrangement.

       Therefore, all books in `left` will be visible from the left.

    4. Select another occurrence for the right group:
        if (freq >= 2) right.push_back(h[i]);

       If a height appears at least twice, we reserve one additional
       copy for the right group.

       This allows us to make another occurrence of that height
       visible from the right.

    5. Put remaining duplicates into the middle:
        for (int k = 2; k < freq; k++)
            middle.push_back(h[i]);

       One occurrence has already been assigned to `left`.

       If the frequency is at least two, another occurrence has been
       assigned to `right`.

       Every remaining occurrence is placed in `middle`.

       These books will not be visible from either side because
       another book of equal or greater height blocks their visibility.

    6. Move to the next distinct height:
        i = j;

       Continue processing until every group has been handled.

    7. Handle the case where no height is duplicated:
        if (right.empty()) {
            right.push_back(left.back());
            left.pop_back();
        }

       If all heights are distinct, no element was added to `right`.

       We move the largest height from `left` to `right`.

       This ensures that the arrangement has a right-side visible
       book as well.

       The largest height is used because it is already the maximum
       element and can be placed at the right end.

    8. Construct the final arrangement:

        for (int x : left) ans.push_back(x);
        for (int x : middle) ans.push_back(x);

       First, append all books from `left` in increasing order.
       Then append all remaining duplicate books.

        reverse(right.begin(), right.end());

       The `right` group was collected in increasing order.
       Reverse it so that its elements appear in decreasing order
       in the final arrangement.

        for (int x : right) ans.push_back(x);

       Append the right group at the end.

       This produces the final arrangement:

           left + middle + reversed(right)

    9. Calculate the number of visible books:
        cout << left.size() + right.size() << "\n";

       Every book in `left` is visible from the left.

       Every book in `right` is visible from the right.

       Books in `middle` are not counted.

       Therefore, the total number of visible books is:

           left.size() + right.size()

    Example:
        n = 6
        h = [1, 2, 2, 3, 3, 3]

        After sorting:
            [1, 2, 2, 3, 3, 3]

        Process height 1:
            freq = 1
            left  = [1]
            right = []
            middle = []

        Process height 2:
            freq = 2
            left  = [1, 2]
            right = [2]
            middle = []

        Process height 3:
            freq = 3
            left  = [1, 2, 3]
            right = [2, 3]
            middle = [3]

        `right` is reversed:
            right = [3, 2]

        Final arrangement:
            left + middle + right

            [1, 2, 3] + [3] + [3, 2]

            ans = [1, 2, 3, 3, 3, 2]

        Visible from the left:
            1, 2, 3

        Visible from the right:
            2, 3

        Total visible books:
            3 + 2 = 5

        Output:
            5
            1 2 3 3 3 2

    Why This Construction Is Optimal:
    Consider a height that occurs `freq` times.

    Since visibility requires a book to be strictly taller than
    every book on the corresponding side, at most one occurrence
    of a particular height can be visible from the left.

    Similarly, at most one occurrence of that height can be visible
    from the right.

    Therefore:
        - If a height occurs once, at most one copy can be visible.
        - If a height occurs at least twice, at most two copies
          can be visible.

    Our construction achieves exactly this:
        - One copy of every distinct height is placed in `left`.
        - A second copy, whenever available, is placed in `right`.

    The middle group contains all remaining copies.

    Hence, the construction reaches the maximum possible number
    of visible books.

    Complexity Analysis:

    Let n be the number of books.

    - Time Complexity: O(n log n)
      Sorting the array takes O(n log n).
      Grouping equal elements takes O(n).
      Constructing the final arrangement takes O(n).
      Therefore, the overall time complexity is O(n log n).

    - Space Complexity: O(n)
      The `left`, `right`, `middle`, and `ans` vectors together
      store O(n) elements.

    Core Idea:
    Sort the heights and process equal-height groups.

    Keep one occurrence of every distinct height for the left side
    and one additional occurrence for the right side whenever possible.

    Put all remaining duplicates in the middle.

    This arrangement maximizes the number of books visible from
    at least one side.
*/