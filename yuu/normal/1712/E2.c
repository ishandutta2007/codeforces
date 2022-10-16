#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
lcm(i, j, k) >= i + j + k
lcm(i, j, k) >= 3k -> always true
lcm(i, j, k) == 2k -> i | 2k, j | 2k, i nor j | k
lcm(i, j, k) == k -> i, j | k, always false
*/

struct query_t {
    int l, r;
    int id;
} a[100001], buffer[100001];

void merge_sort(int l, int r) {
    if (r - l <= 1) return;
    int m = (l + r) / 2;
    merge_sort(l, m);
    merge_sort(m, r);
    int x = l, y = m, p = 0;
    while ((x < m) && (y < r)) {
        if (a[x].l < a[y].l) buffer[p++] = a[x++];
        else buffer[p++] = a[y++];
    }
    while (x < m) buffer[p++] = a[x++];
    while (y < r) buffer[p++] = a[y++];
    for (int i = l; i < r; i++) a[i] = buffer[i - l];
}

int ft[200001];
void ft_update(int u, int x) {
    for (; u <= 200000; u += u & -u) ft[u] += x;
}
int ft_get(int u) {
    int res = 0;
    for (; u > 0; u -= u & -u) res += ft[u];
    return res;
}

int divisor[200001];
// lcm == k
void insert_lower(int d) {
    for (int k = d + d; k <= 200000; k += d) {
        ft_update(k, divisor[k]);  // pair with an existing divisor
        divisor[k]++;
    }
}

void erase_lower(int d) {
    for (int k = d + d; k <= 200000; k += d) {
        // lcm == k
        divisor[k]--;
        ft_update(k, -divisor[k]);  // pair with an existing divisor
    }
}

struct divisor_t {
    struct divisor_t* prev;
    int value;
};
struct divisor_t* g[200001];

void add_divisor(int x, int d) {
    struct divisor_t* new_divisor = malloc(sizeof(struct divisor_t));
    new_divisor->value = d;
    new_divisor->prev = g[x];
    g[x] = new_divisor;
}

struct pop_list_t {
    struct pop_list_t* prev;
    int r;
};
struct pop_list_t* pop[200001];

void add_pop(int i, int j, int k) {
    if (i > j) {
        i ^= j;
        j ^= i;
        i ^= j;
    }
    assert(i < j);
    assert(j < k);
    assert((k * 2) % i == 0);
    assert((k * 2) % j == 0);
    assert((k % i) || (k % j));
    static int pop_cnt = 0;
    pop_cnt++;
    if (pop_cnt % 1000 == 0) fprintf(stderr, "Pop count: %d\n", pop_cnt);
    struct pop_list_t* new_pop = malloc(sizeof(struct pop_list_t));
    new_pop->prev = pop[i];
    new_pop->r = k;
    pop[i] = new_pop;
}

void prepare() {
    for (int i = 1; i <= 200000; i++)
        for (int j = i + i; j <= 200000; j += i) add_divisor(j, i);
    for (int i = 1; i <= 200000; i++) {
        struct divisor_t* a = g[i];
        while (a != NULL) {
            struct divisor_t* b = a->prev;
            while (b != NULL) {
                if (a->value + b->value * 2 <= i) break;
                if ((b->value * 2 < i) && (b->value * 2 != a->value) && (i % (b->value * 2)))
                    add_pop(a->value, b->value * 2, i);

                b = b->prev;
            }
            if ((a->value * 2 < i) && (i % (a->value * 2))) {
                b = a->prev;
                while (b != NULL) {
                    if (a->value * 2 + b->value <= i) break;
                    add_pop(a->value * 2, b->value, i);
                    b = b->prev;
                }
            }
            if ((a->value * 2 < i) && (i % (a->value * 2))) {
                b = a->prev;
                while (b != NULL) {
                    if (a->value * 2 + b->value * 2 <= i) break;
                    if ((b->value * 2 < i) && (i % (b->value * 2))) add_pop(a->value * 2, b->value * 2, i);
                    b = b->prev;
                }
            }
            a = a->prev;
        }
    }
}

int64_t ans[100001];

void solve() {
    prepare();
    int q;
    scanf("%d", &q);
    for (int i = 1; i <= q; i++) {
        scanf("%d %d", &a[i].l, &a[i].r);
        a[i].id = i;
    }
    merge_sort(1, q + 1);

    // for (int i = 1; i <= q; i++) {
    //     printf("%d %d %d\n", a[i].l, a[i].r, a[i].id);
    // }
    for (int i = 1; i <= 200000; i++) {
        insert_lower(i);
        struct pop_list_t* to_pop = pop[i];
        while (to_pop != NULL) {
            ft_update(to_pop->r, 1);
            to_pop = to_pop->prev;
        }
    }
    for (int i = 1, j = 1; i <= 200000; i++) {
        while ((j <= q) && (a[j].l == i)) {
            int64_t n = a[j].r - a[j].l + 1;
            n = n * (n - 1) * (n - 2) / 6;
            ans[a[j].id] = n - ft_get(a[j].r);
            j++;
        }
        erase_lower(i);
        struct pop_list_t* to_pop = pop[i];
        while (to_pop != NULL) {
            ft_update(to_pop->r, -1);
            to_pop = to_pop->prev;
        }
    }
    for (int i = 1; i <= q; i++) printf("%lld\n", ans[i]);
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}