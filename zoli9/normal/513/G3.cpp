#include <bits/stdc++.h>
using namespace std;

int const N = 100;
int const M = 900;
typedef double (*F)[N];

int a[N];
double _f[N][N], _g[N][N];
F f = _f, g = _g;

inline int c2(int n) { return n * (n + 1) >> 1; }

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i=0; i<n; ++i) scanf("%d", a+i);
    int n2 = c2(n);
    for (k=min(k,M); k--; ) {
        for (int i=0; i<n; ++i) for (int j=i+1; j<n; ++j) {
            g[i][j] = (c2(i) + c2(n-1-j) + c2(j-i-1)) * f[i][j];
            for (int x=i; x<i+j; ++x) {
                int a = max(0, x-j+1), b = min(i, x-i);
                g[i][j] += (b - a + 1) * f[x-i][j];
            }
            for (int x=i+j+1; x<n+j; ++x) {
                int a = max(i+1, x-n+1), b = min(j, x-j);
                g[i][j] += (b - a + 1) * f[i][x-j];
            }
            for (int x=j; x<n+i; ++x) {
                int a = max(0, x-n+1), b = min(i, x-j);
                g[i][j] += (b - a + 1) * (1 - f[x-j][x-i]);
            }
            g[i][j] /= n2;
        }
        swap(f, g);
    }
    double e = 0;
    for (int i=0; i<n; ++i) for (int j=i+1; j<n; ++j) {
        e += a[i] > a[j] ? 1 - f[i][j] : f[i][j];
    }
    printf("%.16f\n", e);
    return 0;
}