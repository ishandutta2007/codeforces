#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, sz;
int range_size;
int cache_bit, cache_size;
int a[1 << 18];
struct range_t {
    int64_t s;
    int64_t s_l;
    int64_t s_r;
    int64_t s_max;
} cache[1 << 9][1 << 9];
int b[1 << 9];

void make_cache(int range_id, int permu_id) {
    struct range_t* r = &cache[range_id][permu_id];
    r->s = 0;
    r->s_l = 0;
    r->s_r = 0;
    r->s_max = 0;
    int64_t min_prefix = 0;
    for (int i = 0; i < cache_size; i++) {
        r->s += b[i];
        if (min_prefix > r->s) min_prefix = r->s;
        if (r->s_l < r->s) r->s_l = r->s;
        if (r->s_max < r->s - min_prefix) r->s_max = r->s - min_prefix;
    }
    int64_t sum = 0;
    for (int i = cache_size - 1; i >= 0; i--) {
        sum += b[i];
        if (r->s_r < sum) r->s_r = sum;
    }
}

int permu = 0;

int64_t get_ans() {
    int64_t s = 0;
    int64_t s_l = 0;
    int64_t s_r = 0;
    int64_t s_max = 0;
    int64_t n_s, n_s_l, n_s_r, n_s_max;
    for (int i = 0; i < range_size; i++) {
        struct range_t* r = &cache[i ^ (permu >> cache_bit)][permu & (cache_size - 1)];
        // printf("%lld %lld %lld %lld + %lld %lld %lld %lld\n", s, s_l, s_r, s_max, r->s, r->s_l, r->s_r, r->s_max);
        n_s = s + r->s;
        n_s_l = s_l;
        if (n_s_l < s + r->s_l) n_s_l = s + r->s_l;
        n_s_r = r->s_r;
        if (n_s_r < r->s + s_r) n_s_r = r->s + s_r;
        n_s_max = s_max;
        if (n_s_max < r->s_max) n_s_max = r->s_max;
        if (n_s_max < s_r + r->s_l) n_s_max = s_r + r->s_l;
        s = n_s;
        s_l = n_s_l;
        s_r = n_s_r;
        s_max = n_s_max;
    }
    return s_max;
}

void write(int64_t x) {
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}
void writeln(int64_t x) {
    write(x);
    putchar('\n');
}
void solve() {
    scanf("%d", &n);
    sz = 1 << n;
    for (int i = 0; i < sz; i++) scanf("%d", &a[i]);
    cache_bit = n / 2;
    cache_size = 1 << cache_bit;
    range_size = sz / cache_size;
    for (int start = 0; start < sz; start += cache_size) {
        int range_id = start >> cache_bit;
        for (int permu = 0; permu < cache_size; permu++) {
            for (int i = 0; i < cache_size; i++) b[i] = a[start + (i ^ permu)];
            make_cache(range_id, permu);
        }
    }
    int q;
    scanf("%d", &q);
    for (int i = 1, k; i <= q; i++) {
        scanf("%d", &k);
        permu ^= (1 << k);
        writeln(get_ans());
    }
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}