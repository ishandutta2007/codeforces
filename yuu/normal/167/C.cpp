#include <bits/stdc++.h>
using namespace std;
bool win(int64_t a, int64_t b) {
    if (a < b) swap(a, b);   // a >= b
    if (b == 0) return 0;    // b == 0 then first play lose
    bool t = win(b, a % b);  // first player can try to play the mod move
    if (!t) return 1;        // if the 2nd player can't win at that state then first player win

    // note that (b, a % b) is a winning state, so both player don't want to put the opponent there
    // which mean that the players will be taking turn reducing a by some values which are power of b >= b
    a /= b;  // a is now the amount of single move that can be made;

    // the game is transformed to avoid reducing a to 0, each turn we take power of b >= 1 away
    if (b % 2) {
        // if b is odd, then every power of b is also odd, which mean each move can only change the parity of a
        // which mean if a is even, then the 2nd player will be the one reducing a to 0 and the winner will be the first
        return (a % 2) == 0;
    }

    // if a <= b then the game is pretty much the same as the odd case, only parity matter
    // (note that the a = b -> a = 0 move is useless because that make whoever play it lose)
    // So if a <= b is even first player win.

    // if a >= b + 1, there is a way to for first player to win if and only if a % (b + 1) is even
    //   - if a % (b + 1) == 0 then we use the move b -> a % (b + 1) == 1, which has odd value % (b + 1)
    //   - if a % (b + 1) > 0 then we use the move 1 -> (a - 1) % (b + 1)  = a % (b + 1) - 1, which is also odd
    //   - So we force the other player to play with an odd value of a % (b + 1), no matter what the starting value is
    // if a % (b + 1) is odd, then there's no way to win
    //   - if we play 1 or b^2 or ..., then the value become even, and the player can make it odd again
    //   - if we play b or b^2 or ..., then the value still become even, because we cannot wrap around because b % (b + 1) != b
    return (a % (b + 1)) % 2 == 0;
}
void solve() {
    int64_t a, b;
    cin >> a >> b;
    if (win(a, b)) cout << "First\n";
    else cout << "Second\n";
}
int main() {
    int t;
    cin >> t;
    while (t--) solve();
}