#include <bits/stdc++.h>
using namespace std;

const int N = 45;

int a[N][N], n, m;

vector <int> b[N];

void out_(bool ok) {
    printf("%s\n", ok ? "ACCEPTED" : "REJECTED");
    exit(0);
}

void dfs_(int k) {
    if (k == m) {
        for (int j = 0; j < n; j++)
            if (a[k][j] == -1) out_(0);

        for (int j = 1; j < n; j++)
            if (a[k][j] < a[k][j - 1]) out_(0);
        
        return;
    }

    for (int j = 0; j < n; j++)
        a[k + 1][j] = a[k][j];
    
    int x = 0, y = 0, z = 0;

    for (int i : b[k])
        if (!a[k][i]) x++;
        else if (a[k][i] > 0) y++;
        else z++;
    
    for (int i = 0; i < x + z; i++)
        a[k + 1][b[k][i]] = 0;
    
    for (int i = x + z; i < x + y + z; i++)
        a[k + 1][b[k][i]] = 1;

    for (int i = 0; i <= z; i++) {
        dfs_(k + 1);

        if (i != z) a[k + 1][b[k][x + z - i - 1]] = 1;
    }
}

int main() {
    scanf("%d%d", &n, &m);

    for (int i = 0, k; i < m; i++) {
        scanf("%d", &k);

        for (int j = 0, x; j < k; j++)
            scanf("%d", &x), b[i].push_back(x - 1);
    }

    if (n == 1) out_(1);

    for (int i = 0; i < n; i++)
        a[0][i] = -1;

    dfs_(0);

    out_(1);
}