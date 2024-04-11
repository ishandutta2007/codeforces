#include <bits/stdc++.h>

const int kN = 2e5 + 5;

int a[kN], x[kN], b[kN];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%d", b + i);
    for(int i = 1; i <= n; ++i) {
        a[i] = x[i - 1] + b[i];
        x[i] = std::max(x[i - 1], x[i - 1] + b[i]);
        printf("%d ", a[i]);
    }
    return 0;
}