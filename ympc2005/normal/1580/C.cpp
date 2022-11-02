#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10, M = 310;

int n, m, a[N], b[N], c[N], f[M][M], B = 300, t[N];

void upd_(int x, int k, int T) {
    if (a[x] + b[x] > B) {
        for (int i = t[x] + a[x], j = 1; i <= m; ) {
            if (i > T)
                c[i] += j*k;
            
            i += j == 1 ? b[x] : a[x];
            j *= -1;
        }

        if (k == -1 && (T - t[x])%(a[x] + b[x]) >= a[x])
            c[T]--;
        
        return;
    }
    
    int S = a[x] + b[x];

    for (int j = a[x] + t[x]%S; j < S; j++)   
        f[S][j] += k;
    
    T = t[x]%S;

    for (int j = max(0, T - b[x]); j < T; j++)
        f[S][j] += k;
}

int main() {
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++)
        scanf("%d%d", &a[i], &b[i]);
    
    for (int i = 1, x, y; i <= m; i++) {
        scanf("%d%d", &x, &y), c[i] += c[i - 1];

        if (x == 1) t[y] = i, upd_(y, 1, i);
        else upd_(y, -1, i);
        
        int ans = c[i];

        for (int j = 2; j <= B; j++)
            ans += f[j][i%j];
        
        printf("%d\n", ans);
    }
}