#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
bool bad[256][256];
char s[3], t[3];
char a = 'a', b = 'b', c = 'c';

void test(const char* f) {
    if (bad[f[0]][f[1]]) return;
    if (bad[f[1]][f[2]]) return;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < n; j++) putchar(f[i]);
    exit(0);
}

void solve() {
    scanf("%d", &n);
    scanf("%s %s", &s, &t);
    bad[s[0]][s[1]] = 1;
    bad[t[0]][t[1]] = 1;
    puts("YES");
    if ((!bad[a][b]) && (!bad[b][c]) && (!bad[c][a])) {
        for (int i = 1; i <= n; i++) {
            putchar('a');
            putchar('b');
            putchar('c');
        }
        return;
    }
    if ((!bad[a][c]) && (!bad[c][b]) && (!bad[b][a])) {
        for (int i = 1; i <= n; i++) {
            putchar('a');
            putchar('c');
            putchar('b');
        }
        return;
    }
    assert(!bad[a][a]);
    assert(!bad[b][b]);
    assert(!bad[c][c]);
    test("abc");
    test("acb");
    test("bac");
    test("bca");
    test("cab");
    test("cba");
    assert(false);
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}