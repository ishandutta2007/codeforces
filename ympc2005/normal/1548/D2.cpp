#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 6006;

ll ans1, ans2;

int n, x[N], y[N], c[4][4][4];

int gcd_(int a, int b) {
    return b ? gcd_(b, a%b) : a;
}

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) 
        scanf("%d%d", &x[i], &y[i]);
    
    for (int i = 1; i <= n; i++) {
        memset(c, 0, sizeof(c));

        for (int j = 1; j <= n; j++)
            if (i != j)
                c[x[j]%4][y[j]%4][gcd_(abs(x[j] - x[i]), abs(y[j] - y[i]))%4]++;
            
        int ox = x[i]%4, oy = y[i]%4;
        
        for (int x = 0; x < 4; x++) for (int y = 0; y < 4; y++) for (int k = 0; k < 4; k++) 
            for (int u = x&1; u < 4; u += 2) for (int v = y&1; v < 4; v += 2) for (int w = k&1; w < 4; w += 2) {
                int S = ((u - ox)*(y - oy)%4 - (x - ox)*(v - oy)%4 + 8)%4;

                if (S&1) continue;

                int val = (k + w + (u != x || v != y)*2)%4;

                if (val != S) continue;

                int res = c[x][y][k]*(c[u][v][w] - (x == u && y == v && k == w));

                if (k&1) ans2 += res;
                else ans1 += res;
            }
    }

    printf("%lld\n", ans1/6 + ans2/2);
}