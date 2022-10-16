#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

void write(int n) {
    if (n > 9) write(n / 10);
    putchar('0' + n % 10);
}

int n;
struct {
    int p;
    bool start, up;
} node[200001];
int buffer[200001];
void trace(int u) {
    int pos = 0;
    buffer[++pos] = u;
    while (node[u].up) {
        u = node[u].p;
        buffer[++pos] = u;
    }
    write(pos);
    putchar('\n');
    for (int i = pos; i >= 1; i--) {
        write(buffer[i]);
        putchar(' ');
    }
    putchar('\n');
}
void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &node[i].p);
    for (int i = 1; i <= n; i++) node[i].start = 1;
    for (int i = 1; i <= n; i++) node[i].up = 0;
    node[0].start = node[0].up = 0;
    for (int i = 1; i <= n; i++)
        if (node[i].p == i) node[i].p = 0;
    for (int i = 1; i <= n; i++)
        if (node[i].start) {
            int u = i;
            while (node[node[u].p].start) {
                node[u].up = 1;
                u = node[u].p;
                node[u].start = 0;
            }
        }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (node[i].start) ans++;
    write(ans);
    putchar('\n');
    for (int i = 1; i <= n; i++)
        if (node[i].start) {
            trace(i);
        }
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}