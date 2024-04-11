#include <cstdio>
#include <cassert>
#include <cstring>
using namespace std;


int main() {
    int n;
    scanf("%d", &n);
    int L = 0, R = 20 * 1000;
    int y = R;
    bool bad = false;
    for (int i = 0; i < n; i++) {
        int t;
        char dir[10];
        scanf("%d %s", &t, dir);
        if (strcmp(dir, "North") == 0) {
            y += t;
            if (y > R) {
                bad = true;
                break;
            }
        } else if (strcmp(dir, "South") == 0) {
            y -= t;
            if (y < L) {
                bad = true;
                break;
            }
        } else if (strcmp(dir, "West") == 0 || strcmp(dir, "East") == 0) {
            if (y == L || y == R) {
                bad = true;
                break;
            }
        } else {
            assert(false);
        }
    }
    if (y != R) {
        bad = true;
    }
    puts(bad ? "NO" : "YES");
}