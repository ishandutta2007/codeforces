#include <bits/stdc++.h>
using namespace std;

typedef vector<int> poly;
typedef unsigned long long ull;
const int maxn = 1048576, P = 998244353;
int n, m, K, a[maxn], vis[maxn], pre[maxn], nxt[maxn];
int lim, L, r[maxn], w[maxn], ban[maxn];
vector<int> G[maxn];

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}
 
void init(int n) {
    for (lim = 1, L = 0; lim < n; lim <<= 1) L++;
    for (int i = 0; i < lim; i++) r[i] = (r[i >> 1] >> 1) | ((i & 1) << (L - 1));
    w[lim >> 1] = 1;
    int t = qp(3, (P - 1) / lim);
    for (int i = (lim >> 1) + 1; i < lim; i++) w[i] = 1LL * w[i - 1] * t % P;
    for (int i = (lim >> 1) - 1; i > 0; i--) w[i] = w[i << 1];
}
 
void DFT(int *a, int type) {
    static ull c[maxn];
    copy(a, a + lim, c);
    for (int i = 0; i < lim; i++) if (i < r[i]) swap(c[i], c[r[i]]);
    for (int i = 1; i < lim; i <<= 1) {
        for (int j = 0; j < lim; j += i << 1) {
            for (int k = 0; k < i; k++) {
                ull t = c[i + j + k] * w[i + k] % P;
                c[i + j + k] = c[j + k] + P - t, c[j + k] += t;
            }
        }
    }
    if (!~type) {
        reverse(c + 1, c + lim);
        for (int i = 0, t = qp(lim, P - 2); i < lim; i++) c[i] = c[i] % P * t % P;
    }
    for (int i = 0; i < lim; i++) a[i] = c[i] % P;
}
 
poly operator * (poly C, poly B) {
    int len = C.size() + B.size() - 1;
    init(len), C.resize(lim), B.resize(lim);
    DFT(C.data(), 1), DFT(B.data(), 1);
    for (int i = 0; i < lim; i++) C[i] = 1LL * C[i] * B[i] % P;
    DFT(C.data(), -1), C.resize(len); return C;
}
 
poly inv(poly A) {
    if (A.size() == 1) return {qp(A[0], P - 2)};
    int m = (A.size() + 1) / 2;
    poly B = inv(poly{A.begin(), A.begin() + m}), C = A * B;
    C.resize(A.size()), fill(C.begin(), C.begin() + m, 0);
    poly ans = B;
    ans.resize(A.size()), C = C * B;
    for (int i = m; i < A.size(); i++) ans[i] = (P - C[i]) % P;
    return ans;
}

int main() {
    scanf("%d %d %d", &n, &m, &K);
    memset(pre, -1, sizeof(pre));
    memset(nxt, -1, sizeof(nxt));
    for (int i = 1, c; i <= n; i++) {
        scanf("%d", &c);
        for (int j = 1; j <= c; j++) {
            scanf("%d", &a[j]);
        }
        for (int j = 1; j < c; j++) {
            if (~nxt[a[j]] && nxt[a[j]] != a[j + 1]) ban[a[j]] = 1;
            nxt[a[j]] = a[j + 1];
            if (~pre[a[j + 1]] && pre[a[j + 1]] != a[j]) ban[a[j + 1]] = 1;
            pre[a[j + 1]] = a[j];
            G[a[j]].push_back(a[j + 1]), G[a[j + 1]].push_back(a[j]);
        }
    }
    poly A(m + 1);
    function<void(int)> dfs = [&](int v) {
        for (int u : G[v]) if (!ban[u]) {
            ban[u] = 1, dfs(u);
        }
    };
    for (int i = 1; i <= K; i++) {
        if (ban[i]) dfs(i);
    }
    for (int i = 1; i <= K; i++) if (!vis[i] && !ban[i] && !~pre[i]) {
        int cnt = 0;
        for (int j = i; ~j; j = nxt[j]) {
            assert(!vis[j]);
            vis[j] = 1, cnt++;
        }
        if (cnt <= m) (A[cnt] += P - 1) %= P;
    }
    A[0]++, A = inv(A);
    printf("%d\n", A[m]);
    return 0;
}