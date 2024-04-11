#include <bits/stdc++.h>
using namespace std;

const int N = 5005;

int T, n, f[N][N], g[N];

char s[N];

int main() {
    scanf("%d", &T);

    while (T--) {
        scanf("%d%s", &n, s + 1);

        for (int i = n; i; i--)
            for (int j = n; j > i; j--)
                if (s[i] != s[j])
                    f[i][j] = 0;
                else 
                    f[i][j] = 1 + (j < n ? f[i + 1][j + 1] : 0);

        g[1] = n;

        for (int i = 2; i <= n; i++) {
            g[i] = n - i + 1;

            for (int j = 1; j < i; j++)
                if (f[j][i] != n - i + 1 && s[i + f[j][i]] > s[j + f[j][i]])    
                    g[i] = max(g[i], g[j] + n - i + 1 - f[j][i]);
        }

        int ans = 0;

        for (int i = 1; i <= n; i++)
            ans = max(ans, g[i]);
        
        printf("%d\n", ans);
    }
}