#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

bool transform[4][4][4];

void make(int current_fill, int next, bool* f) {
    for (int i = 0; i < 4; i++) f[i] = 0;
    if ((current_fill == 0) || (current_fill == 3)) {  // vertical on prev row
        f[next] = 1;
        if (next == 0) f[3] = 1;  // vertical on current row
    }
    for (int horizontal_mask = 0; horizontal_mask < 4; horizontal_mask++) {
        // no clash
        if ((horizontal_mask & 1) && (current_fill & 1)) continue;
        if ((horizontal_mask & 2) && (current_fill & 2)) continue;
        if ((horizontal_mask & 1) && (next & 1)) continue;
        if ((horizontal_mask & 2) && (next & 2)) continue;
        // prev row is filled
        if ((current_fill | horizontal_mask) != 3) continue;
        f[next | horizontal_mask] = 1;
    }
}
struct solution_matrix {
    bool f[4][4];
} power_0[30], trans[4];

void combine(struct solution_matrix a, struct solution_matrix b, struct solution_matrix* c) {
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++) {
            c->f[i][j] = 0;
            for (int k = 0; k < 4; k++) {
                c->f[i][j] += a.f[i][k] * b.f[k][j];
            }
        }
}

void combine_zeros(int zero_count, struct solution_matrix* req) {
    if (zero_count <= 0) return;
    for (int i = 29; i >= 0; i--)
        if ((zero_count >> i) & 1) {
            combine(*req, power_0[i], req);
        }
}

void prepare() {
    for (int tile_mask = 0; tile_mask < 4; tile_mask++) {
        for (int prev_mask = 0; prev_mask < 4; prev_mask++) {
            make(prev_mask, tile_mask, transform[tile_mask][prev_mask]);
        }
    }
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++) power_0[0].f[i][j] = transform[0][i][j];
    for (int i = 1; i < 30; i++) {
        combine(power_0[i - 1], power_0[i - 1], &power_0[i]);
    }
    for (int t = 0; t < 4; t++)
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++) trans[t].f[i][j] = transform[t][i][j];
    // for (int t = 0; t < 4; t++){
    //     printf("Trans: %d\n", t);
    //     for (int i = 0; i < 4; i++){
    //         for (int j = 0; j < 4; j++) printf("%d ", trans[t].f[i][j]);
    //         printf("\n");
    //     }
    // }
}
int n, m;
struct {
    int r, c;
} b[200001], buffer[200001];

void merge_sort(int l, int r) {
    if (l >= r) return;
    int m = (l + r) / 2;
    merge_sort(l, m);
    merge_sort(m + 1, r);
    int x = l, y = m + 1;
    int t = 0;
    while ((x <= m) && (y <= r)) {
        if (b[x].c < b[y].c) buffer[t++] = b[x++];
        else buffer[t++] = b[y++];
    }
    while (x <= m) buffer[t++] = b[x++];
    while (y <= r) buffer[t++] = b[y++];
    for (int i = l; i <= r; i++) b[i] = buffer[i - l];
}

void solve() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) scanf("%d %d", &b[i].r, &b[i].c);
    merge_sort(1, m);
    struct solution_matrix ans;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++) ans.f[i][j] = 0;
    ans.f[0][0] = 1;
    int current_col = 0;
    for (int i = 1; i <= m; i++) {
        if (b[i].c == b[i - 1].c) continue;
        int mask = b[i].r;
        if ((i < m) && (b[i + 1].c == b[i].c)) mask |= b[i + 1].r;
        combine_zeros(b[i].c - current_col - 1, &ans);
        current_col = b[i].c;
        combine(ans, trans[mask], &ans);
    }
    combine_zeros(n - current_col - 1, &ans);
    if (ans.f[0][3]) printf("YES\n");
    else printf("NO\n");
}

int main() {
    prepare();
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}