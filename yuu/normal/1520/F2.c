#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;
int ask(int pos) {
    printf("? 1 %d\n", pos);
    fflush(stdout);
    int res = 0;
    scanf("%d", &res);
    assert(res != -1);
    return pos - res;
}

void guess(int ans) {
    printf("! %d\n", ans);
    fflush(stdout);
}

int binary_search(int l, int r, int value) {
    int ans = -1;
    while (l <= r) {
        int m = (l + r) / 2;
        int res = ask(m);
        if (res >= value) {
            ans = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    return ans;
}

#define BUCKET_SIZE 31

int bucket_count;
int bucket_start[200001];
int bucket_end[200001];
int bucket_total[200001];

int ft[200001];

void update(int u) {
    for (; u <= bucket_count; u += (u & -u)) ft[u]--;
}

int get_bucket(int id) {
    int res = bucket_total[id];
    for (; id > 0; id -= (id & -id)) res += ft[id];
    return res;
}

int binary_search_bucket(int value) {
    int low = 1, high = bucket_count, mid, res;
    while (low <= high) {
        mid = (low + high) / 2;
        if (get_bucket(mid) >= value) {
            res = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return res;
}

void start_sequence() {
    for (int i = 1; i <= n; i += BUCKET_SIZE) {
        bucket_count++;
        bucket_start[bucket_count] = i;
        bucket_end[bucket_count] = i + BUCKET_SIZE - 1;
        if (bucket_end[bucket_count] > n) bucket_end[bucket_count] = n;
        bucket_total[bucket_count] = ask(bucket_end[bucket_count]);
    }
}

void solve() {
    int t;
    scanf("%d %d", &n, &t);

    for (int i = 1, k; i <= t; i++) {
        scanf("%d", &k);
        if (i == 1) start_sequence();
        int bucket = binary_search_bucket(k);
        guess(binary_search(bucket_start[bucket], bucket_end[bucket], k));
        update(bucket);
    }
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}