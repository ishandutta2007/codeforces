#include <bits/stdc++.h>
using namespace std;

const int maxn = 30010;
int n, t, a[maxn], f[maxn];

int main() {
    scanf("%d %d", &n, &t);
    for (int i = f[1] = 1, a; i < n; i++) {
        scanf("%d", &a), f[i + a] |= f[i];
    }
    puts(f[t] ? "YES" : "NO");
    return 0;
}