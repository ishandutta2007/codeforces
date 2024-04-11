#include <bits/stdc++.h>
using namespace std;

const int N = 100006;
int a[N];
int b[N];

void go() {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    int mn = *min_element(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; ++i) {
        if (a[i] % mn != 0 && a[i] != b[i]) {
            puts("NO");
            return;
        }
    }
    puts("YES");
}

int main () {
    int T; scanf("%d", &T);
    while (T--) {
        go();
    }
}