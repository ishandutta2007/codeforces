#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
int a[200001];
void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int mx = 0;
    for (int i = 1; i <= n; i++)
        if (a[i] > mx) mx = a[i];
    int mx_cnt = 0, mx_n1_cnt = 0;
    for (int i = 1; i <= n; i++)
        if (a[i] == mx)
            mx_cnt++;
        else if (a[i] + 1 == mx)
            mx_n1_cnt++;
    if ((mx_cnt + mx_n1_cnt >= 2) || (mx == 1))
        printf("YES\n");
    else
        printf("NO\n");
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}