#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int T, n, f[N][2], g[N][2];

char s[N], t[N];

int main() {
    scanf("%d", &T);

    while (T--) {
        scanf("%d%s", &n, s + 1);
        memset(f, 0x3f, sizeof(f));
        f[0][0] = f[0][1] = 0;

        for (int i = 1; i <= n; i++) {
            if (s[i] == '?' || s[i] == 'B') {
                if (f[i - 1][0] + 1 >= f[i - 1][1]) 
                    f[i][0] = f[i - 1][1], g[i][0] = 1;
                else
                    f[i][0] = f[i - 1][0] + 1, g[i][0] = 0;
            } 

            if (s[i] == '?' || s[i] == 'R') {
                if (f[i - 1][1] + 1 >= f[i - 1][0]) 
                    f[i][1] = f[i - 1][0], g[i][1] = 0;
                else
                    f[i][1] = f[i - 1][1] + 1, g[i][1] = 1;
            }
        }

        int x = f[n][0] > f[n][1];

        for (int i = n; i; i--)
            t[i] = x ? 'R' : 'B', x = g[i][x];
        
        for (int i = 1; i <= n; i++)
            printf("%c", t[i]);
        
        puts("");
    }
}