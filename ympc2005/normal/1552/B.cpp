#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int T, n, id, rk[N][5];

bool chk_(int u, int v) {
    int cnt = 0;

    for (int i = 0; i < 5; i++)
        cnt += rk[u][i] < rk[v][i];
    
    return cnt > 2;
}

int main() {
    scanf("%d", &T);

    while (T--) {
        scanf("%d", &n);

        for (int i = 1; i <= n; i++)
            for (int j = 0; j < 5; j++)
                scanf("%d", &rk[i][j]);
        
        id = 1;

        for (int i = 2; i <= n; i++)
            if (chk_(i, id))
                id = i;
        
        bool ok = 1;

        for (int i = 1; i <= n; i++)
            if (i != id && chk_(i, id))
                ok = 0;

        if (!ok) id = -1;

        printf("%d\n", id);
    }
}