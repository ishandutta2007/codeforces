#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int next_int() {
    char c;
    while (c = getchar()) {
        if ((c >= '0') && (c <= '9')) break;
    }
    int res = c - 48;
    while (c = getchar()) {
        if ((c < '0') || (c > '9')) break;
        res *= 10;
        res += (c - 48);
    }
    return res;
}

int greater(const void* A, const void* B) { return *((int*)B) - *((int*)A); }

int n, k;
int x[400000];
int buff[400000];
void merge_sort(int l, int r) {
    if (l == r) return;
    int m = (l + r) / 2;
    merge_sort(l, m);
    merge_sort(m + 1, r);
    int ls = l, rs = m + 1;
    int pos = 0;
    while ((ls <= m) && (rs <= r)) {
        if (x[ls] > x[rs]) {
            buff[pos++] = x[ls++];
        } else {
            buff[pos++] = x[rs++];
        }
    }
    while (ls <= m) buff[pos++] = x[ls++];
    while (rs <= r) buff[pos++] = x[rs++];
    for (int i = l; i <= r; i++) x[i] = buff[i - l];
}
bool check(int m) {
    int cat_pos = 0;
    for (int i = m - 1; i >= 0; i--) {
        if (x[i] <= cat_pos) return false;
        cat_pos += n - x[i];
    }
    return true;
}

void solve() {
    // scanf("%d %d", &n, &k);
    n = next_int();
    k = next_int();
    // for (int i = 0; i < k; i++) scanf("%d", &x[i]);
    for (int i = 0; i < k; i++) x[i] = next_int();
    // qsort(x, k, sizeof(int), greater);
    merge_sort(0, k - 1);
    int low = 1, high = k, mid, ans = 0;
    while (low <= high) {
        mid = (low + high) / 2;
        if (check(mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    printf("%d\n", ans);
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}