#include <bits/stdc++.h>
using namespace std;
const int maxM = 21, maxN = (1 << maxM) + 3;

int m, n;
char s[maxN], t[maxN];
long long a[maxN], b[maxN], c[maxN];

void fwt(long long f[], int sgn) {
    for (int len = 1; len < n; len <<= 1) {
        for (int i = 0; i < n; i += len << 1) {
            for (int j = 0; j < len; j++) { f[i + j + len] += sgn * f[i + j]; }
        }
    }
}

int main() {
    scanf("%d%s%s", &m, s, t); n = 1 << m;
    for (int i = 0; i < n; i++) { a[i] = (s[i] & 15ll) << (__builtin_popcount(i) << 1); } fwt(a, 1);
    for (int i = 0; i < n; i++) { b[i] = (t[i] & 15ll) << (__builtin_popcount(i) << 1); } fwt(b, 1);
    for (int i = 0; i < n; i++) { 
		c[i] = a[i] * b[i]; } fwt(c, -1);
    for (int i = 0; i < n; i++) { putchar(c[i] >> (__builtin_popcount(i) << 1) & 3 | 48); }
    return 0;
}