#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
int read();
int M(int x) { return x >= mod ? x - mod : x; }
const int lim = 1 << 16;
int n;
char s[502];
map<char, int> trans;
int f[502][70004], g[9][70004];
void init() {
    trans['A'] = 1, trans['B'] = 2, trans['C'] = 3, trans['D'] = 4;
    trans['a'] = 5, trans['b'] = 6, trans['c'] = 7, trans['d'] = 8;
    trans['&'] = 9, trans['|'] = 10, trans['?'] = 11;

    for (int i = 1; i <= 4; ++i) {
        int t = 0;
        for (int j = 0; j < 16; ++j) t |= ((j >> (i - 1)) & 1) << j;
        ++g[i][t], ++g[i + 4][t ^ (lim - 1)], ++g[0][t], ++g[0][t ^ (lim - 1)];
    }
}
int ch[200005][2], type[200005], p, idcnt;

void work(int u) {
    if (s[p] == '?') return;
    if (isalpha(s[p])) return type[u] = trans[s[p]], void();
    int v = ++idcnt;
    ++p, ch[u][0] = v, work(v);
    type[u] = trans[s[p += 2]], v = ++idcnt;
    p += 2, ch[u][1] = v, work(v), ++p;
}

void work_and(int *f, int *x, int *y);
void work_or(int *f, int *x, int *y);

int tx[70004], ty[70004];
void dfs(int u) {
    if (type[u] <= 8) {
        for (int i = 0; i < lim; ++i) f[u][i] = g[type[u]][i];
        return;
    }
    dfs(ch[u][0]), dfs(ch[u][1]);
    if (type[u] == 9) return work_and(f[u], f[ch[u][0]], f[ch[u][1]]);
    if (type[u] == 10) return work_or(f[u], f[ch[u][0]], f[ch[u][1]]);
    for (int i = 0; i < lim; ++i)
        tx[i] = f[ch[u][0]][i], ty[i] = f[ch[u][1]][i];
    work_and(f[u], tx, ty), work_or(f[0], f[ch[u][0]], f[ch[u][1]]);
    for (int i = 0; i < lim; ++i) f[u][i] = M(f[u][i] + f[0][i]);
}

int ck[2];

int main() {
    init(), scanf("%s", s + 1), p = 1, work(idcnt = 1), dfs(1), n = read();
    for (int i = 1, A, B, C, D, t; i <= n; ++i) {
        A = read(), B = read(), C = read(), D = read();
        ck[read()] |= 1 << (A | (B << 1) | (C << 2) | (D << 3));
    }
    ck[0] ^= lim;
    int res = 0;
    for (int i = 0; i < lim; ++i)
        if ((i | ck[1]) == i && (i & ck[0]) == 0) res = M(res + f[1][i]);
    printf("%d\n", res);
    return 0;
}
const int _SIZE = 1 << 22;
char ibuf[_SIZE], *iS = ibuf, *iT = ibuf;
#define gc                                                         \
    (iS == iT ? iT = ((iS = ibuf) + fread(ibuf, 1, _SIZE, stdin)), \
     (iS == iT ? EOF : *iS++) : *iS++)
int read() {
    int x = 0, f = 1;
    char c = gc;
    while (!isdigit(c)) f = (c == '-') ? -1 : f, c = gc;
    while (isdigit(c)) x = x * 10 + c - '0', c = gc;
    return x * f;
}

void fwt_and(int *x) {
    for (int l = 2; l <= lim; l <<= 1)
        for (int i = 0, m = l >> 1; i < lim; i += l)
            for (int j = i; j < i + m; ++j) x[j] = M(x[j] + x[j + m]);
}
void ifwt_and(int *x) {
    for (int l = 2; l <= lim; l <<= 1)
        for (int i = 0, m = l >> 1; i < lim; i += l)
            for (int j = i; j < i + m; ++j) x[j] = M(x[j] + mod - x[j + m]);
}
void work_and(int *f, int *x, int *y) {
    fwt_and(x), fwt_and(y);
    for (int i = 0; i < lim; ++i) f[i] = 1ll * x[i] * y[i] % mod;
    ifwt_and(f);
}
void fwt_or(int *x) {
    for (int l = 2; l <= lim; l <<= 1)
        for (int i = 0, m = l >> 1; i < lim; i += l)
            for (int j = i; j < i + m; ++j) x[j + m] = M(x[j] + x[j + m]);
}
void ifwt_or(int *x) {
    for (int l = 2; l <= lim; l <<= 1)
        for (int i = 0, m = l >> 1; i < lim; i += l)
            for (int j = i; j < i + m; ++j) x[j + m] = M(x[j + m] + mod - x[j]);
}
void work_or(int *f, int *x, int *y) {
    fwt_or(x), fwt_or(y);
    for (int i = 0; i < lim; ++i) f[i] = 1ll * x[i] * y[i] % mod;
    ifwt_or(f);
}