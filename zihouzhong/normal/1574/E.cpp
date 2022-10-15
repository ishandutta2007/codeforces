#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000010, P = 998244353;
int n, m, K, pw[maxn];
int cntr, okr, cr[maxn][2];
int cntc, okc, cc[maxn][2];
map<pair<int, int>, int> mp;

int main() {
    scanf("%d %d %d", &n, &m, &K);
    for (int i = pw[0] = 1; i <= max(n, m); i++) {
        pw[i] = 2 * pw[i - 1] % P;
    }
    auto updr = [&](int x, int coef) {
        if (cr[x][0] || cr[x][1]) cntr += coef;
        if (cr[x][0] && cr[x][1]) okr += coef;
    };
    auto updc = [&](int x, int coef) {
        if (cc[x][0] || cc[x][1]) cntc += coef;
        if (cc[x][0] && cc[x][1]) okc += coef;
    };
    int flag0 = 0, flag1 = 0;
    while (K--) {
        int x, y, c;
        scanf("%d %d %d", &x, &y, &c);
        int lst = -1;
        if (mp.count({x, y})) lst = mp[{x, y}];
        updr(x, -1), updc(y, -1);
        if (~lst) {
            flag0 -= (lst == ((x + y) & 1));
            flag1 -= (lst != ((x + y) & 1));
            cr[x][lst ^ (y & 1)]--;
            cc[y][lst ^ (x & 1)]--;
        }
        if (~c) {
            flag0 += (c == ((x + y) & 1));
            flag1 += (c != ((x + y) & 1));
            cr[x][c ^ (y & 1)]++;
            cc[y][c ^ (x & 1)]++;
        }
        updr(x, 1), updc(y, 1);
        if (~c) mp[{x, y}] = c;
        else mp.erase({x, y});
        int ans = 0;
        if (!okr) ans = pw[n - cntr];
        if (!okc) (ans += pw[m - cntc]) %= P;
        if (!flag0) ans = (ans + P - 1) % P;
        if (!flag1) ans = (ans + P - 1) % P;
        printf("%d\n", ans);
    }
    return 0;
}