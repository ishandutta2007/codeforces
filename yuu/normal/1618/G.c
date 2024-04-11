#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Query {
    int k, id;
};
struct Query qr[200000];
int sort_by_k(const void* a, const void* b) { return ((struct Query*)(a))->k - ((struct Query*)(b))->k; }

typedef struct Item {
    int value;
    bool is_a;
};
struct Item c[400000];
int sort_by_value(const void* a, const void* b) { return ((struct Item*)(a))->value - ((struct Item*)(b))->value; }

typedef struct Update {
    int diff;
    int left;
};
struct Update u[400000];

int sort_by_diff(const void* a, const void* b) { return ((struct Update*)(a))->diff - ((struct Update*)(b))->diff; }
int n, m, q;

int64_t prefix[400000];
int64_t ans[200000];
int64_t current_ans;

int r[400000];
int h[400000];
int s[400000];

int root(int u) {
    if (r[u] < 0) return u;
    return r[u] = root(r[u]);
}

int64_t get_sum(int pos, int length) {
    assert(pos + 1 >= length);
    if (pos + 1 == length)
        return prefix[pos];
    else
        return prefix[pos] - prefix[pos - length];
}

void change_component(int u, int d) {
    assert(u == root(u));
    current_ans += get_sum(h[u], s[u]) * d;
}

void unite(int u, int v) {
    u = root(u);
    v = root(v);
    assert(u != v);
    change_component(u, -1);
    change_component(v, -1);
    if (r[u] > r[v]) {
        u ^= v;
        v ^= u;
        u ^= v;
    }
    r[u] += r[v];
    r[v] = u;
    if (h[u] < h[v]) h[u] = h[v];
    s[u] += s[v];
    change_component(u, 1);
}

void solve() {
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i].value);
        c[i].is_a = true;
    }

    for (int i = 0; i < m; i++) {
        scanf("%d", &c[i + n].value);
        c[i + n].is_a = false;
    }

    qsort(c, n + m, sizeof(struct Item), sort_by_value);

    for (int i = 0; i + 1 < n + m; i++) {
        u[i].diff = c[i + 1].value - c[i].value;
        u[i].left = i;
    }
    qsort(u, n + m - 1, sizeof(struct Update), sort_by_diff);

    for (int i = 0; i < q; i++) {
        scanf("%d", &qr[i].k);
        qr[i].id = i;
    }
    qsort(qr, q, sizeof(struct Query), sort_by_k);

    for (int i = 0; i < n + m; i++) {
        r[i] = -1;
        h[i] = i;
        if (c[i].is_a) {
            s[i] = 1;
            current_ans += c[i].value;
        } else {
            s[i] = 0;
        }
        if (i)
            prefix[i] = prefix[i - 1] + c[i].value;
        else
            prefix[i] = c[i].value;
    }

    for (int i = 0, j = 0; i < q; i++) {
        while ((j < n + m - 1) && (u[j].diff <= qr[i].k)) {
            unite(u[j].left, u[j].left + 1);
            j++;
        }
        ans[qr[i].id] = current_ans;
    }
    for (int i = 0; i < q; i++) printf("%lld\n", ans[i]);
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}