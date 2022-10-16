#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char s[1000002];
int n, q;
int tree[4000001];

int make(char c) {
    if ((c == '(') || (c == ')')) return 1;
    return -1;
}

int combine(int left, int right) {
    if (left == 0) return right;
    if (right == 0) return left;
    if (left < 0) {
        if (left % 2) {       // end with [
            if (right > 0) {  // start with (
                return -(abs(left) + abs(right));
            } else {  // start with [
                if (abs(left) >= abs(right))
                    return -abs(abs(left) - abs(right));
                else
                    return abs(abs(left) - abs(right));
            }
        } else {              // end with (
            if (right < 0) {  // start with [
                return -(abs(left) + abs(right));
            } else {  // start with (
                if (abs(left) >= abs(right))
                    return -abs(abs(left) - abs(right));
                else
                    return abs(abs(left) - abs(right));
            }
        }
    } else {
        if (left % 2 == 0) {  // end with [
            if (right > 0) {  // start with (
                return (abs(left) + abs(right));
            } else {  // start with [
                if (abs(left) >= abs(right))
                    return abs(abs(left) - abs(right));
                else
                    return -abs(abs(left) - abs(right));
            }
        } else {              // end with (
            if (right < 0) {  // start with [
                return (abs(left) + abs(right));
            } else {  // start with (
                if (abs(left) >= abs(right))
                    return abs(abs(left) - abs(right));
                else
                    return -abs(abs(left) - abs(right));
            }
        }
    }
}
void build(int id, int l, int r) {
    if (l == r) {
        tree[id] = make(s[l]);
    } else {
        int m = (l + r) / 2;
        build(id * 2, l, m);
        build(id * 2 + 1, m + 1, r);
        tree[id] = combine(tree[id * 2], tree[id * 2 + 1]);
        // printf("%d %d %d\n", l, r, tree[id]);
    }
}

int get(int id, int l, int r, int u, int v) {
    if ((l > v) || (r < u)) return 0;
    if ((u <= l) && (v >= r))
        return tree[id];
    else {
        int m = (l + r) / 2;
        int res =  combine(get(id * 2, l, m, u, v), get(id * 2 + 1, m + 1, r, u, v));
        // printf("Q: %d %d %d %d %d\n", l, r, u, v, res);
        return res;
    }
}

void solve() {
    scanf("%s", &s[1]);
    n = strlen(&s[1]);
    // printf("%d\n", n);
    // for (int i = 1; i <= n; i++) printf("%c", s[i]);
    // printf("\n");
    fflush(stdout);
    scanf("%d", &q);
    build(1, 1, n);
    for (int i = 1, l, r; i <= q; i++) {
        scanf("%d %d\n", &l, &r);
        printf("%d\n", abs(get(1, 1, n, l, r)) / 2);
    }
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}