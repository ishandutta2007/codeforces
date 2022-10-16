#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
bool good[1000001];

void prepare() {
    good[0] = 1;
    good[2020] = 1;
    for (int i = 2021; i <= 1000000; i++) {
        good[i] = (good[i - 2020] || good[i - 2021]);
    }
}
void solve() {
    int n;
    scanf("%d", &n);
    if (good[n]) printf("YES\n");
    else printf("NO\n");
}

int main() {
    prepare();
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}