#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char n[20];
int len;
char t[20];
void debug_output() {
    for (int i = 0; i < len; i++) putchar('0' + t[i]);
    putchar('\n');
}
int get(int a, int b) {
    for (int i = 0; i <= len; i++) t[i] = n[i];
    int last = len - 1;
    while ((last >= 0) && (t[last] != b) && (t[last] != a)) last--;
    // bax -> axb -> xab = 3
    // bax -> bxa -> xab = 3
    if (last <= 0) return 1e9;
    int rem = a + b - t[last];

    int ans = 0;
    for (int i = last + 1; i < len; i++) {
        ans++;
        t[i] ^= t[i - 1];
        t[i - 1] ^= t[i];
        t[i] ^= t[i - 1];
    }
    // printf("%d: %d %d\n", __LINE__, a, b);
    // debug_output();
    last--;
    while ((last >= 0) && (t[last] != rem)) last--;
    // printf("%d: %d %d\n", __LINE__, a, b);
    // debug_output();
    if (last < 0) return 1e9;
    // printf("%d: %d %d\n", __LINE__, a, b);
    // debug_output();
    if ((last == 0) && (t[1] == 0) && (len > 2)) {
        // fix the leading zero first
        int f = 1;
        while ((f < len) && (t[f] == 0)) f++;
        if (f >= len - 1) return 1e9;
        while (f) {
            ans++;
            t[f] ^= t[f - 1];
            t[f - 1] ^= t[f];
            t[f] ^= t[f - 1];
            f--;
        }
        last = 1;
    }
    // printf("%d: %d %d\n", __LINE__, a, b);
    // debug_output();
    for (int i = last + 1; i < len - 1; i++) {
        ans++;
        t[i] ^= t[i - 1];
        t[i - 1] ^= t[i];
        t[i] ^= t[i - 1];
    }
    // printf("%d: %d %d\n", __LINE__, a, b);
    // debug_output();
    if ((t[len - 1] != b) || (t[len - 2] != a)) {
        ans++;  // fix the swap
        int i = len - 1;
        t[i] ^= t[i - 1];
        t[i - 1] ^= t[i];
        t[i] ^= t[i - 1];
    }
    // printf("%d: %d %d\n", __LINE__, a, b);
    // debug_output();
    if (t[0] == 0) return 1e9;
    if ((t[len - 1] != b) || (t[len - 2] != a)) return 1e9;

    return ans;
}
void solve() {
    scanf("%s", &n);
    len = strlen(n);
    if (len == 1) {
        puts("-1");
        return;
    }
    bool good = false;
    for (int i = 0; i < len; i++) n[i] -= '0';
    for (int i = 0; i < len; i++) {
        if ((n[i] == 0) || (n[i] == 5)) {
            good = true;
            break;
        }
    }
    if (!good) {
        puts("-1");
        return;
    }
    int end_in_5 = 0;
    int ans = 1e9;
    int res;

    res = get(0, 0);
    if (ans > res) ans = res;
    // printf("%d\n\n", res);

    res = get(2, 5);
    if (ans > res) ans = res;
    // printf("%d\n\n", res);

    res = get(5, 0);
    if (ans > res) ans = res;
    // printf("%d\n\n", res);

    res = get(7, 5);
    if (ans > res) ans = res;
    // printf("%d\n\n", res);

    if (ans == 1e9) ans = -1;
    printf("%d\n", ans);
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}