#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;
int a[2001];
int temp[2001];
int ans[2001];

void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = n; i >= 1; i--) {
        int pos = 1;
        while ((pos <= i) && (a[pos] != i)) pos++;
        if (pos > i) {
            printf("-1\n");
            return;
        }
        if (pos == i) {
            ans[i] = 0;
        } else {
            ans[i] = pos;
            for (int j = 1; j <= i; j++) temp[j] = a[j];
            for (int j = i, source = pos; j >= 1; j--) {
                a[j] = temp[source];
                source--;
                if (source == 0) source = i;
            }
        }
    }
    for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
    printf("\n");
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}