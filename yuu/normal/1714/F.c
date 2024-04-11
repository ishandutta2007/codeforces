#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
int d[4][4];
void solve() {
    scanf("%d %d %d %d", &n, &d[1][2], &d[2][3], &d[3][1]);
    if ((d[1][2] + d[2][3] + d[3][1]) % 2) {
        puts("NO");
        return;
    }
    d[2][1] = d[1][2];
    d[3][2] = d[2][3];
    d[1][3] = d[3][1];
    int a = 1, b = 2, c = 3;
    for (int i = 1; i <= 3; i++) {
        for (int j = i + 1; j <= 3; j++) {
            if (d[i][j] > d[a][b]) {
                a = i;
                b = j;
            }
        }
    }
    // d[a][b] is the longest
    c = 6 - a - b;
    if (d[a][c] + d[b][c] < d[a][b]) {
        puts("NO");
        return;
    }
    int distance_from_path = (d[a][c] + d[b][c] - d[a][b]) / 2;
    int distance_from_a = d[a][c] - distance_from_path;
    int distance_from_b = d[b][c] - distance_from_path;
    assert(distance_from_a + distance_from_b == d[a][b]);
    int min_node_required = d[a][b] + 1 + distance_from_path;
    if (min_node_required > n) {
        puts("NO");
        return;
    }
    // can be done
    puts("YES");
    int vertex = 3;
    if (distance_from_path == 0) {
        int last = a;
        for (int i = 1; i <= distance_from_a - 1; i++) {
            printf("%d %d\n", last, ++vertex);
            last = vertex;
        }
        printf("%d %d\n", last, c);
        last = c;
        for (int i = 1; i <= distance_from_b - 1; i++) {
            printf("%d %d\n", last, ++vertex);
            last = vertex;
        }
        printf("%d %d\n", last, b);
    } else {
        int last = a;
        for (int i = 1; i <= distance_from_a; i++) {
            printf("%d %d\n", last, ++vertex);
            last = vertex;
        }
        int attach_to = last;
        for (int i = 1; i <= distance_from_b - 1; i++) {
            printf("%d %d\n", last, ++vertex);
            last = vertex;
        }
        printf("%d %d\n", last, b);
        last = attach_to;
        for (int i = 1; i <= distance_from_path - 1; i++) {
            printf("%d %d\n", last, ++vertex);
            last = vertex;
        }
        printf("%d %d\n", last, c);
    }
    int last = 1;
    while (vertex < n) {
        printf("%d %d\n", last, ++vertex);
        last = vertex;
    }
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}