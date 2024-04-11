#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
char s[200001];
int ans[200000];

int item[2][200001];
int size[2];

void stack_clear(int id) { size[id] = 0; }

void stack_push(int id, int x) { item[id][++size[id]] = x; }

int stack_pop(int id) { return item[id][size[id]--]; }

int stack_empty(int id) { return size[id] == 0; }
void solve() {
    scanf("%d", &n);
    scanf("%s", &s);
    stack_clear(0);
    stack_clear(1);
    int required = 0;
    for (int i = 0; i < n; i++) {
        int b = s[i] - '0';
        if (stack_empty(1 - b)) ans[i] = ++required;
        else ans[i] = stack_pop(1 - b);
        stack_push(b, ans[i]);
    }
    printf("%d\n", required);
    for (int i = 0; i < n; i++) printf("%d ", ans[i]);
    printf("\n");
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}