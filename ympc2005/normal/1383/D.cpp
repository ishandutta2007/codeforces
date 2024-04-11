#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int n, m, a[N][N], b[N][N];

bool fx[N*N], fy[N*N];

queue <int> qx, qy;

int main() {
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++) {
        int mx = 0;

        for (int j = 1; j <= m; j++) {
            scanf("%d", &a[i][j]);
            mx = max(mx, a[i][j]);
        }

        fx[mx] = 1;
    }

    for (int j = 1; j <= m; j++) {
        int mx = 0;

        for (int i = 1; i <= n; i++) {
            mx = max(mx, a[i][j]);
        }

        fy[mx] = 1;
    }

    int cx = 0, cy = 0;
    
    for (int i = n*m; i; i--) {
        if (fx[i]) {
            cx++;
        }

        if (fy[i]) {
            cy++;
        }

        if (fx[i] || fy[i]) {
            b[cx][cy] = i;
        } else {
            b[qx.front()][qy.front()] = i;
            qx.pop(); qy.pop();
        }

        if (fx[i]) {
            for (int i = cy - 1; i; i--) {
                qx.push(cx);
                qy.push(i);
            }
        }

        if (fy[i]) {
            for (int i = cx - 1; i; i--) {
                qx.push(i);
                qy.push(cy);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            printf("%d ", b[i][j]);
        }

        puts("");
    }
}