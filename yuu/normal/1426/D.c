#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;
int a[200001];
struct Node {
    struct Node* g[2];
    bool end;
};

struct Node root;

void Reset() {
    root.g[0] = root.g[1] = NULL;
    root.end = false;
}

void Free(struct Node* node) {
    if (node->g[0]) {
        Free(node->g[0]);
        free(node->g[0]);
    }
    if (node->g[1]) {
        Free(node->g[1]);
        free(node->g[1]);
    }
}

bool Add(int64_t x) {
    struct Node* node = &root;
    x += 2e15;
    while (x) {
        int b = x % 2;
        if (!node->g[b]) {
            node->g[b] = malloc(sizeof(struct Node));
            node->g[b]->g[0] = node->g[b]->g[1] = NULL;
            node->g[b]->end = false;
        }
        node = node->g[b];
        x /= 2;
    }
    if (node->end) return false;
    node->end = true;
    return true;
}

void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    Reset();
    int64_t sum = 0;
    Add(sum);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        sum += a[i];
        if (!Add(sum)) {
            ans++;
            Free(&root);
            Reset();
            sum = 0;
            Add(sum);
            sum = a[i];
            Add(sum);
        }
    }
    printf("%d\n", ans);
}
int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}