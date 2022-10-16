#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
int id[1 << 17];
int win[1 << 17];

void write(int x) {
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}
int ask(int a, int b) {
    putchar('?');
    putchar(' ');
    write(a);
    putchar(' ');
    write(b);
    putchar('\n');
    fflush(stdout);
    int res;
    scanf("%d", &res);
    return res;
}

void guess(int x) {
    putchar('!');
    putchar(' ');
    write(x);
    putchar('\n');
    fflush(stdout);
}

int find_sole_winner(int a, int b) {
    int res = ask(a, b);
    if (res == 1) return a;
    else if (res == 2) return b;
    else assert(0);
}
int find_winner(int* a) {
    int res_first = ask(a[0], a[2]);
    if (res_first == 1) {
        // a[0] > a[2]
        return find_sole_winner(a[0], a[3]);
    } else if (res_first == 2) {
        return find_sole_winner(a[2], a[1]);
    } else {
        return find_sole_winner(a[1], a[3]);
    }
}

void solve() {
    // 2 * 2^n / 4 = 2 ^ (n - 1)
    // 4 / 3 * 2 ^ (n - 1)
    // 2 / 3 * 2^(n - 2)
    // 2 ^ (n - 2)
    scanf("%d", &n);
    for (int i = 0; i < (1 << n); i++) {
        id[i] = i + 1;
    }
    while (n >= 2) {
        for (int i = 0; i < (1 << n); i += 4) win[i >> 2] = find_winner(&id[i]);
        n -= 2;
        for (int i = 0; i < (1 << n); i++) id[i] = win[i];
    }
    if (n == 1) {
        guess(find_sole_winner(id[0], id[1]));
    } else {
        guess(id[0]);
    }
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}