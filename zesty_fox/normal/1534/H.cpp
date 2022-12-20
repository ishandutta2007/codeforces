#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

template <typename T> inline T read() {
    T x = 0, f = 0;
    char ch = getchar();
    while (!isdigit(ch))
        f |= (ch == '-'), ch = getchar();
    while (isdigit(ch))
        x = x * 10 + (ch ^ 48), ch = getchar();
    return f ? -x : x;
}

#define rdi read<int>
#define rdll read<ll>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int N = 100010, INF = 0x3f3f3f3f;

int n;

vi e[N];
int f[N], fa[N], q[N];
vi son[N];

auto cmp = [](const int &a, const int &b) { return f[a] > f[b]; };

void dfs(int x, int fat) {
    fa[x] = fat, q[x] = x;
    for (auto y : e[x]) {
        if (y == fat)
            continue;
        dfs(y, x);
        son[x].pb(y);
    }
    sort(son[x].begin(), son[x].end(), cmp);
    if (son[x].size())
        q[x] = q[son[x][0]];
    for (int i = 0; i < (int)son[x].size(); i++) {
        int y = son[x][i];
        f[x] = max(f[x], f[y] + i);
    }
}

int ff[N], qf[N];

void dfs1(int x, int fa) {
    if (fa) {
        int tmp = f[fa];
        f[fa] = ff[x];
        son[x].insert(lower_bound(son[x].begin(), son[x].end(), fa, cmp), fa);
        f[fa] = tmp;
    }

    auto get = [&](int u) { return u == fa ? ff[x] : f[u]; };

    int cnt = son[x].size();
    int mx1 = -INF, p1 = 0, mx2 = -INF, p2 = 0;
    for (int i = 0; i < cnt; i++) {
        int y = son[x][i], val = get(y) + i;
        if (val > mx1)
            mx2 = mx1, p2 = p1, mx1 = val, p1 = i;
        else if (val > mx2)
            mx2 = val, p2 = i;
    }
    mx1 = max(mx1, 0), mx2 = max(mx2, 0);

    int q1 = son[x][0] == fa ? qf[x] : q[son[x][0]];
    int q2 =
        (son[x].size() <= 1 ? x : (son[x][1] == fa ? qf[x] : q[son[x][1]]));
    for (int i = 0; i < cnt; i++) {
        int y = son[x][i];
        if (y == fa)
            continue;
        ff[y] = (i == p1 ? mx2 - (p2 > i) : mx1 - (p1 > i));
        qf[y] = i ? q1 : q2;
    }
    for (auto y : e[x])
        if (y != fa)
            dfs1(y, x);
}

int fa1[N];
void dfs2(int x, int fat) {
    fa1[x] = fat;
    for (auto y : e[x])
        if (y != fat)
            dfs2(y, x);
}

int query(int x) {
    cout << "? " << x << endl;
    return rdi();
}

int find(int x) {
    int cnt = 0;
    for (auto y : son[x]) {
        if (y == fa1[x])
            continue;
        if (cnt) {
            int to = query(y == fa[x] ? qf[x] : q[y]);
            if (to != x)
                return find(to);
        }
        cnt++;
    }
    return x;
}

void solve(int rt) {
    dfs2(rt, 0);
    int a = 0, b = 0;
    for (auto y : son[rt]) {
        int x = query(y == fa[rt] ? qf[rt] : q[y]);
        if (x != rt)
            (!a ? a : b) = find(x);
        if (b)
            break;
    }
    if (!a)
        a = rt;
    if (!b)
        b = rt;
    cout << "! " << a << " " << b << endl;
}

int main() {
    n = rdi();
    if (n == 1) {
        cout << 0 << endl;
        cout << "! 1 1" << endl;
        return 0;
    }
    for (int i = 1; i < n; i++) {
        int x = rdi(), y = rdi();
        e[x].pb(y), e[y].pb(x);
    }
    dfs(1, 0);
    dfs1(1, 0);
    int res = 0;
    for (int i = 1; i <= n; i++) {
        int mx1 = 0;
        for (int j = 0; j < (int)son[i].size(); j++) {
            int y = son[i][j];
            int val = (y == fa[i] ? ff[i] : f[y]);
            res = max(res, mx1 + val + j + 1);
            mx1 = max(mx1, val);
        }
    }
    cout << res << endl;
    solve(rdi());
    return 0;
}