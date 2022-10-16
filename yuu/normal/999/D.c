#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n, m;
int a[200001];
struct item_t {
    struct item_t* prev;
    int pos;
};
struct item_t* g[200000];
struct item_t* moving_list;
struct item_t* add_item(struct item_t* prev, int pos) {
    struct item_t* new_item = malloc(sizeof(struct item_t));
    new_item->prev = prev;
    new_item->pos = pos;
    return new_item;
}

int cnt[200000];

void solve() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        g[a[i] % m] = add_item(g[a[i] % m], i);
        cnt[a[i] % m]++;
    }
    int streak = 0;
    int target = n / m;
    int begin = -1;
    int moving_list_size = 0;
    for (int i = 0; streak <= m; i = (i + 1) % m) {
        streak++;
        while ((cnt[i] < target) && (moving_list_size > 0)) {
            g[i] = add_item(g[i], moving_list->pos);
            moving_list = moving_list->prev;
            cnt[i]++;
            moving_list_size--;
            streak = 0;
        }
        while (cnt[i] > target) {
            moving_list = add_item(moving_list, g[i]->pos);
            g[i] = g[i]->prev;
            cnt[i]--;
            moving_list_size++;
            streak = 0;
        }
    }
    int64_t ans = 0;
    for (int i = 0; i < m; i++) {
        struct item_t* item = g[i];
        while (item != NULL) {
            int p = item->pos;
            item = item->prev;
            int current = a[p] % m;
            if (current <= i) {
                a[p] += i - current;
                ans += i - current;
            } else {
                a[p] += i + m - current;
                ans += i + m - current;
            }
        }
    }
    printf("%lld\n", ans);
    for (int i = 1; i <= n; i++) printf("%d ", a[i]);
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}