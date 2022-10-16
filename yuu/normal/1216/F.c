#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int64_t f[200001][2];
// f[i][0] -> mincost to cover from 1 to i
// f[i][1] -> mincost to cover from 1 to i, with i having a wifi router

int n, k;
char s[200002];
struct deque_t {
    int deque[200001];
    int front_ptr;
    int back_ptr;
} dq[2];

void clear(int id) {
    dq[id].front_ptr = 0;
    dq[id].back_ptr = -1;
}

int size(int id) { return dq[id].back_ptr - dq[id].front_ptr + 1; }
bool empty(int id) { return dq[id].back_ptr < dq[id].front_ptr; }

void pop_front(int id) { dq[id].front_ptr++; }
void pop_back(int id) { dq[id].back_ptr--; }
void push_back(int id, int u) { dq[id].deque[++dq[id].back_ptr] = u; }

int front(int id) { return dq[id].deque[dq[id].front_ptr]; }
int back(int id) { return dq[id].deque[dq[id].back_ptr]; }

void solve() {
    scanf("%d %d", &n, &k);
    scanf("%s", &s[1]);
    clear(0);
    clear(1);
    push_back(0, 0);
    for (int i = 1; i <= n; i++) {
        while ((!empty(0)) && (i - front(0) > k + 1)) pop_front(0);
        while ((!empty(1)) && (i - front(1) > k)) pop_front(1);
        f[i][0] = f[i - 1][0] + i;
        f[i][1] = 1e18;
        if (f[i][0] > f[i - 1][1] + i) f[i][0] = f[i - 1][1] + i;
        if (!empty(1))
            if (f[i][0] > f[front(1)][1]) f[i][0] = f[front(1)][1];
        if (s[i] == '1')  // can place router
            f[i][1] = f[front(0)][0] + i;
        if (f[i][0] > f[i][1]) f[i][0] = f[i][1];
        while ((!empty(0)) && (f[i][0] <= f[back(0)][0])) pop_back(0);
        push_back(0, i);
        if (s[i] == '1') {
            while ((!empty(1)) && (f[i][1] <= f[back(1)][1])) pop_back(1);
            push_back(1, i);
        }
    }
    printf("%lld\n", f[n][0]);
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}