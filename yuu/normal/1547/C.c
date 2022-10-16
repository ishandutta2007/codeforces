#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
int n, m, k;
int a[100];
int b[100];
int ans[200];
void solve() {
    scanf("%d %d %d", &k, &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < m; i++) scanf("%d", &b[i]);
    int i = 0, j = 0, pos = 0;
    while ((i < n) && (j < m)) {
        if (a[i] == 0) {
            k++;
            ans[pos++] = 0;
            i++;
        } else if (b[j] == 0) {
            k++;
            ans[pos++] = 0;
            j++;
        } else if (a[i] <= k) {
            ans[pos++] = a[i];
            i++;
        } else if (b[j] <= k) {
            ans[pos++] = b[j];
            j++;
        } else {
            printf("-1\n");
            return;
        }
    }
    while (i < n) {
        if (a[i] == 0) {
            k++;
            ans[pos++] = 0;
            i++;
        } else if (a[i] <= k) {
            ans[pos++] = a[i];
            i++;
        } else {
            printf("-1\n");
            return;
        }
    }
    while (j < m) {
        if (b[j] == 0) {
            k++;
            ans[pos++] = 0;
            j++;
        } else if (b[j] <= k) {
            ans[pos++] = b[j];
            j++;
        } else {
            printf("-1\n");
            return;
        }
    }
    for (int i = 0; i < n + m; i++) printf("%d ", ans[i]);
    printf("\n");
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}