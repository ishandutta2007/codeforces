#include <bits/stdc++.h>
using namespace std;
#define fu(i, a, b) for(int i = a, I = (b) + 1; i < I; ++i)
#define fd(i, a, b) for(int i = a, I = (b) - 1; i > I; --i)
template <class T> inline void rd(T &x) {
    x = 0; T f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9') f = ch == '-' ? -1 : 1, ch = getchar();
    while(ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    x *= f;
} 

inline void ckmax(int &a, int b) {if(a < b) a = b;}

const int N = 2005;
int n, m, a[N], c[N], w[N << 1], f[N << 1][N];

int main() {
    rd(n), rd(m);
    fu(i, 1, n) rd(a[i]);
    fu(i, 1, n) rd(c[i]);
    fu(i, 1, n + m) rd(w[i]);
    memset(f, 0xcf, sizeof f);
    fu(i, 1, n + m + 1) f[i][0] = 0;
    fd(i, n, 1) {
        fd(j, n, 1) ckmax(f[a[i]][j], f[a[i]][j - 1] + w[a[i]] - c[i]);
        for(int j = a[i], k = n; j <= m + n; ++j, k >>= 1) 
            fu(kk, 0, k) ckmax(f[j + 1][kk >> 1], f[j][kk] + w[j + 1] * (kk >> 1));
    }
    return printf("%d", f[n + m + 1][0]), 0;
}