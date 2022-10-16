#include <stdio.h>
int n;

void recursive_solve(int l, int r) {
    if (l == r) {
        printf("! %d\n", l);
        fflush(stdout);
        return;
    }
    int m = (l + r) / 2 + 1;
    int guess = n - m % n;
    if (guess == n) guess = 1;

    printf("+ %d\n", guess);
    fflush(stdout);
    l += guess;
    r += guess;

    int low = l / n;
    int high = r / n;
    m = high * n - 1;
    int res = 0;
    scanf("%d", &res);
    if (res == low) {
        recursive_solve(l, m);
    } else {
        recursive_solve(m + 1, r);
    }
}

void solve() {
    scanf("%d", &n);
    recursive_solve(1, n - 1);
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}