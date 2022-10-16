#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
int x[3];
int y[3];
int dist(const int a, const int b) { return abs(x[a] - x[b]) + abs(y[a] - y[b]); }
void solve() {
    for (int i = 0; i < 3; i++) scanf("%d %d", &x[i], &y[i]);
    if (dist(0, 1) < dist(0, 2) + dist(2, 1)) {
        printf("%d\n", dist(0, 1));
        return;
    }
    if (abs(x[0] - x[1]) && abs(y[0] - y[1])) {
        printf("%d\n", dist(0, 1));
        return;
    }
    printf("%d\n", dist(0, 1) + 2);
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}