#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n, m;
int s[101];
int d[101];
int c[101];
int exam[101];
int schedule[101];
void solve() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d %d", &s[i], &d[i], &c[i]);
        exam[d[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        if (exam[i]) {
            if (c[exam[i]]) {
                puts("-1");
                return;
            } else {
                schedule[i] = m + 1;
            }
        } else {
            int study_for = 0;
            for (int j = 1; j <= m; j++) {
                if (c[j] == 0) continue;
                if (s[j] <= i) {
                    if ((study_for == 0) || (d[j] < d[study_for])) study_for = j;
                }
            }
            c[study_for]--;
            schedule[i] = study_for;
        }
    }
    for (int i = 1; i <= n; i++) printf("%d ", schedule[i]);
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}