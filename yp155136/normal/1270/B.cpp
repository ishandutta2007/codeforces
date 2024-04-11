#include <bits/stdc++.h>
using namespace std;

const int N = 200006;

int a[N];

void go() {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i < n; ++i) {
        if (abs(a[i] - a[i + 1]) >= 2) {
            puts("YES");
            printf("%d %d\n", i, i + 1);
            return;
        }
    }
    puts("NO");
}

int main () {
    int T; scanf("%d", &T);
    while (T--) {
        go();
    }
}