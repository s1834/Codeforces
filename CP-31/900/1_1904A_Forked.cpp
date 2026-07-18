#include<bits/stdc++.h>
using namespace std;

int main() {
    int dx[4] = {1, 1, -1, -1}, dy[4] = {1, -1, -1, 1};
    
    int t;
    cin >> t;

    while(t--) {
        long long a, b;
        cin >> a >> b;
        
        long long xk, yk;
        cin >> xk >> yk;
        
        long long xq, yq;
        cin >> xq >> yq;
        
        set<pair<int, int>> king, queen;
        for(int i = 0; i < 4; i++) {
            king.insert({xk + a * dx[i], yk + b * dy[i]});
            king.insert({xk + b * dx[i], yk + a * dy[i]});
            queen.insert({xq + a * dx[i], yq + b * dy[i]});
            queen.insert({xq + b * dx[i], yq + a * dy[i]});
        }
        
        int ans = 0;
        
        for(auto x : king) {
            if(queen.find(x) != queen.end()) ans++;
        }
        
        cout << ans << endl;
    }

    return 0;
}

/*

Idea:
------
A knight moving with offsets

(a, b)

can attack up to eight different positions around a
given square.

Generate all possible positions from which a knight
could attack the King's position, and similarly all
positions from which it could attack the Queen's
position.

The common positions in these two sets represent squares
from which a knight can attack both the King and the
Queen simultaneously.

The answer is simply the size of the intersection of
the two sets.

------------------------------------------------------------

Algorithm:
----------

For every test case,

1.

Generate every possible knight position that can attack
the King.

The possible moves are

(±a, ±b)

and

(±b, ±a)

All sign combinations are generated using the direction
arrays.

Store every generated position in a set.

------------------------------------------------------------

2.

Similarly,

generate every possible knight position that can attack
the Queen and store them in another set.

------------------------------------------------------------

3.

Traverse one of the sets.

For every position,

check whether it also exists in the other set.

If yes,

increment the answer.

------------------------------------------------------------

4.

Print the total number of common positions.

------------------------------------------------------------

Why Use a Set?
--------------

A knight can generate at most eight possible attacking
positions.

However,

these positions are not always distinct.

For example,

if

a == b

then

(±a, ±b)

and

(±b, ±a)

represent the same moves, resulting in only four unique
positions instead of eight.

Using a set automatically removes duplicate positions,
ensuring every valid square is counted exactly once.

------------------------------------------------------------

Example:
--------

Suppose

a = 1

b = 2

King Position

(3,3)

Possible attacking positions

(4,5)

(5,4)

(5,2)

(4,1)

(2,1)

(1,2)

(1,4)

(2,5)

Similarly,

generate all possible attacking positions for the Queen.

Any position appearing in both sets is a square from
which one knight attacks both pieces.

------------------------------------------------------------

Time Complexity:
----------------

For each test case,

at most eight positions are generated for the King and
at most eight for the Queen.

Each insertion and lookup in the set takes constant time
for this fixed-size input (or O(log 8), which is still
constant).

Overall Time Complexity:

O(1)

per test case.

------------------------------------------------------------

Space Complexity:
-----------------

O(1)

Each set stores at most eight generated positions (and
possibly fewer after duplicate removal).

*/