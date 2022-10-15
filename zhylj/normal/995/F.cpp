#include <bits/stdc++.h>
 
template <typename T> inline void rd(T& x) {
    int si = 1; char c = getchar(); x = 0;
    while(!isdigit(c)) si = c == '-' ? -1 : si, c = getchar();
    while(isdigit(c)) x = x * 10 + c - 48, c = getchar();
    x *= si;
}
template <typename T, typename... Args>
inline void rd(T& x, Args&... args) { rd(x); rd(args...); }
#define fi first
#define se second
#define mkp std::make_pair
typedef long long ll;
typedef double ff;
typedef std::pair <int, int> pii;
const int N = 3e3 + 5, Inf = 0x3f3f3f3f, Mod = 1e9 + 7;
const ll InfLL = 0x3f3f3f3f3f3f3f3fLL;
 
int QPow(int a, int b) {
    int ret = 1, bas = a;
    for(; b; b >>= 1, bas = 1LL * bas * bas % Mod)
        if(b & 1) ret = 1LL * ret * bas % Mod;
    return ret;
}
 
int n, d;
std::vector <int> E[N];
 
int fac[N], fac_inv[N];
void Init() {
    fac[0] = 1;
    for(int i = 1; i <= n; ++i) fac[i] = 1LL * fac[i - 1] * i % Mod;
    fac_inv[n] = QPow(fac[n], Mod - 2);
    for(int i = n - 1; ~i; --i)
        fac_inv[i] = 1LL * fac_inv[i + 1] * (i + 1) % Mod;
}
int C(int x, int y) {
    if(x < y || y < 0) return 0;
    if(x <= n) return 1LL * fac[x] * fac_inv[y] % Mod * fac_inv[x - y] % Mod;
    else {
        int ret = 1;
        for(int i = 1; i <= y; ++i)
            ret = 1LL * ret * (x - i + 1) % Mod;
        return 1LL * ret * fac_inv[y] % Mod;
    }
}
 
int f[N][N];
void Dfs(int u) {
    for(int i = 1; i <= n; ++i)
        f[u][i] = 1;
    for(auto v : E[u]) {
        Dfs(v);
        for(int i = 1; i <= n; ++i)
            f[u][i] = 1LL * f[v][i] * f[u][i] % Mod;
    }
    for(int i = 1; i <= n; ++i)
        f[u][i] = (f[u][i] + f[u][i - 1]) % Mod;
}
 
int main() {
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
#endif
    int test_case_cnt = 1; //rd(test_case_cnt);
    while(test_case_cnt--) {
        rd(n, d); Init();
        for(int i = 2; i <= n; ++i) {
            int f; rd(f);
            E[f].push_back(i);
        }
        Dfs(1);
        int ans = 0;
        for(int i = 1; i <= n && i <= d; ++i) {
            int cur_ans = 0;
            for(int j = 1; j <= i; ++j) {
                int c = (i - j) % 2 ? -1 : 1;
                cur_ans = (cur_ans + 1LL * c * C(i, j) * f[1][j] % Mod) % Mod;
                cur_ans = (cur_ans + Mod) % Mod;
            }
            ans = (ans + 1LL * cur_ans * C(d, i)) % Mod;
        }
        printf("%d\n", ans);
    } return 0;
}