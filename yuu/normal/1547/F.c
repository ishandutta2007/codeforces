#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
int n;
int a[200000];
int b[200000];
int g[19][200000];
int next_int() {
    char c;
    while (c = getchar()) {
        if ((c >= '0') && (c <= '9')) break;
    }
    int ans = c - '0';
    while (c = getchar()) {
        if ((c < '0') || (c > '9')) break;
        ans *= 10;
        ans += (c - '0');
    }
    return ans;
}

int gcd(int a, int b) {
    while (b) {
        a %= b;
        a ^= b;
        b ^= a;
        a ^= b;
    }
    return a;
}

bool is_equal() {
    for (int i = 1; i < n; i++)
        if (a[i] != a[i - 1]) return false;
    return true;
}

void write(int x) {
    if (x >= 10) write(x / 10);
    putchar(x % 10 + '0');
}

void backup() {
    for (int i = 0; i < n; i++) b[i] = a[i];
}

void unroll() {
    for (int i = 0; i < n; i++) a[i] = b[i];
}

void make(int power) {
    int dist = 1 << power;
    for (int i = 0; i < n; i++) a[i] = gcd(b[(i + dist) % n], g[power][i]);
}

void solve() {
    n = next_int();
    for (int i = 0; i < n; i++) a[i] = next_int();
    if (is_equal()) {
        printf("0\n");
        return;
    }
    for (int i = 0; i < n; i++) g[0][i] = gcd(a[i], a[(i + 1) % n]);
    for (int i = 1, length = 1; i < 19; i++, length *= 2) {
        for (int j = 0; j < n; j++) {
            g[i][j] = gcd(g[i - 1][j], g[i - 1][(j + length) % n]);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) a[i] = 0;
    for (int i = 18; i >= 0; i--) {
        backup();
        make(i);
        if (is_equal())
            unroll();
        else
            ans ^= (1 << i);
    }
    write(ans + 1);
    putchar('\n');
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}