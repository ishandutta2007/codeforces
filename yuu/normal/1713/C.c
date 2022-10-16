#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
int ans[100000];
bool used[100000];
bool is_square[200000];

void prepare() {
    for (int i = 0; i * i < 200000; i++) is_square[i * i] = 1;
}

void write(int x) {
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}

void writesp(int x) {
    write(x);
    putchar(' ');
}
void solve() {
    scanf("%d", &n);
    for (int i = 0; i <= n; i++) used[i] = 0;
    int square = n + n - 1;
    while (!is_square[square]) square--;
    for (int i = n - 1; i >= 0; i--) {
        while ((!is_square[square]) || (square - i >= n) || (used[square - i])) square--;
        // printf("%d %d\n", i, square);
        ans[i] = square - i;
        used[ans[i]] = 1;
    }
    for (int i = 0; i < n; i++) writesp(ans[i]);
    putchar('\n');
}

int main() {
    int t = 1;
    scanf("%d", &t);
    prepare();
    while (t--) solve();
}