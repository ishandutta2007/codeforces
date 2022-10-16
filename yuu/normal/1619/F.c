#include <stdio.h>
int n, m, k;
int ans[200001];
void solve() {
    scanf("%d %d %d", &n, &m, &k);
    int start = 1;
    int n_mod_m = n % m;
    int n_div_m = n / m;
    for (int turn = 1; turn <= k; turn++) {
        int table = 1;
        for (int i = 1; i <= n_mod_m; i++) {
            printf("%d", n_div_m + 1);
            for (int j = 0; j <= n_div_m; j++) {
                printf(" %d", start);
                start++;
                if (start > n) start = 1;
            }
            printf("\n");
        }
        int next_start = start;
        for (int i = n_mod_m + 1; i <= m; i++) {
            printf("%d", n_div_m);
            for (int j = 0; j < n_div_m; j++) {
                printf(" %d", start);
                start++;
                if (start > n) start = 1;
            }
            printf("\n");
        }
        start = next_start;
    }
    printf("\n");
}

int main() {
    int t = 1;
    scanf("%d\n", &t);
    while (t--) solve();
}