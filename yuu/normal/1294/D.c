#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int q, x;
int supply[400000];
void solve() {
    scanf("%d %d", &q, &x);
    int mex = 0;
    for (int i = 1, y; i <= q; i++) {
        scanf("%d", &y);
        supply[y % x]++;
        while (supply[mex % x]) {
            supply[mex % x]--;
            mex++;
        }
        printf("%d\n", mex);
    }
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}