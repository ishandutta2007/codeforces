#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

bitset <N<<1> f;

int T, n, a[N];

bool chk_(int k) {
    f.reset(), f[N] = 1;

    for (int i = 1; i <= n; i++)
        if (i != k)
            f |= (f>>a[i]) | (f<<a[i]);
    
    return f[a[k] + N];
}

int main() {
    scanf("%d", &T);

    while (T--) {
        scanf("%d", &n);
        
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]), a[i] = abs(a[i]);
        
        bool ok = 0;

        for (int i = 1; i <= n; i++)
            if (chk_(i)) {
                ok = 1;
                break;
            }
        
        printf("%s\n", ok ? "YES" : "NO");
    }
}