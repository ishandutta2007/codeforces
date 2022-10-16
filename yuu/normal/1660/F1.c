#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
char str[200002];
int plus[200001];
int plus_cnt = 0;

int64_t ans;

int64_t count_buffer[3][500000];
int64_t* count[3];
int done_buffer[3][500000];
int* done[3];
int step;
void recursive_solve(int l, int h) {
    if (l > h) return;
    int m = (l + h) / 2;
    recursive_solve(l, m - 1);
    recursive_solve(m + 1, h);
    int bound_left = plus[l - 1];
    int bound_right = plus[h + 1];
    int mid = plus[m];
    step++;
    int p = 0, s = 0, d = 0, r = 0;
    int low_weight = 0;
    int height_weight = 0;
    done[0][0] = step;
    count[0][0] = 1;
    for (int i = mid - 1; i > bound_left; i--) {
        if (str[i] == '+') {
            s += r;
            r = 0;
            p++;
        } else {
            d += r;
            r = 1 - r;
        }
        int weight = ((s + r) - p + d * 2);
        int mod3 = weight % 3;
        mod3 = (3 - mod3) % 3;
        if (done[mod3][weight] != step) {
            done[mod3][weight] = step;
            count[mod3][weight] = 1;
        } else {
            count[mod3][weight]++;
        }
        if (weight > height_weight) height_weight = weight;
        if (weight < low_weight) low_weight = weight;
    }
    for (int i = 0; i < 3; i++) {
        count[i][low_weight - 1] = 0;
        for (int j = low_weight; j <= height_weight; j++) {
            if (done[i][j] != step) count[i][j] = 0;
            count[i][j] += count[i][j - 1];
        }
    }
    p = s = d = r = 0;
    for (int i = mid; i < bound_right; i++) {
        if (str[i] == '+') {
            s += r;
            r = 0;
            p++;
        } else {
            d += r;
            r = 1 - r;
        }
        int weight = -((s + r) - p + d * 2);
        int mod3 = weight % 3;
        mod3 = (3 - mod3) % 3;
        if (mod3 < 0) mod3 += 3;
        if (weight < low_weight) weight = low_weight;
        if (weight <= height_weight) ans += count[mod3][height_weight] - count[mod3][weight - 1];
        // fprintf(stderr, "%d %d %d %lld\n", l, h, i, ans);
    }
    // fprintf(stderr, "%d %d %lld\n", l, h, ans);
}

void solve() {
    scanf("%d %s", &n, &str[1]);
    plus_cnt = 0;
    for (int i = 1; i <= n; i++)
        if (str[i] == '+') {
            plus[++plus_cnt] = i;
        }
    ans = 0;
    plus[0] = 0;
    plus[plus_cnt + 1] = n + 1;
    recursive_solve(1, plus_cnt);
    for (int i = 0; i <= plus_cnt; i++) {
        int gap = plus[i + 1] - plus[i] - 1;

        for (int size = 3; size <= gap; size += 3) {
            ans += gap - size + 1;
        }
    }
    printf("%lld\n", ans);
}

int main() {
    for (int i = 0; i < 3; i++) count[i] = &count_buffer[i][250000];
    for (int i = 0; i < 3; i++) done[i] = &done_buffer[i][250000];
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}