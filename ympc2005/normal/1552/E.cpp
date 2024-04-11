#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int N = 105;

int n, m, s[N], t[N], lim, c[N];

vector <int> p[N], a[N];

int main() {
    scanf("%d%d", &n, &m), lim = ceil(1.0*n/(m - 1));

    for (int i = 1, x; i <= n*m; i++)
        scanf("%d", &x), p[++c[x]].push_back(x), a[x].push_back(i);
    
    for (int i = 2; i <= m; i++) {
        int tot = 0;

        for (int j : p[i])
            if (!s[j]) {
                s[j] = a[j][i - 2], t[j] = a[j][i - 1];
                tot++;

                if (tot == lim) break;
            }
    }

    for (int i = 1; i <= n; i++)
        printf("%d %d\n", s[i], t[i]);
}