#pragma GCC optimize(3, "Ofast", "inline")

#include <bits/stdc++.h>

#define start ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define int ll
#define ls st<<1
#define rs st<<1|1
#define pii pair<int,int>
#define rep(z, x, y) for(int z=x;z<=y;++z)
#define com bool operator<(const node &b)
using namespace std;
const int maxn = (ll) 2e5 + 5;
const int mod = (ll) 1e9 + 7;
const int inf = 0x3f3f3f3f;
int T = 1;

struct edge {
    int v, next, w;
} e[maxn << 1];

struct node {
    int dis, u;

    bool operator<(const node &b) const {
        return dis > b.dis;
    }
};

int cnt;
int head[maxn];
int disa[maxn];
int disb[maxn];
int disc[maxn];
bool vis[maxn];

void addedge(int u, int v, int w) {
    e[++cnt].next = head[u];
    e[cnt].v = v;
    e[cnt].w = w;
    head[u] = cnt;
    e[++cnt].next = head[v];
    e[cnt].v = u;
    e[cnt].w = w;
    head[v] = cnt;
}

int n, m, s;

void dijkstra_a() {
    priority_queue<node> q;
    disa[s] = 0;
    node st;
    st.dis = 0;
    st.u = s;
    q.push(st);
    while (!q.empty()) {
        node u = q.top();
        q.pop();
        if (vis[u.u])
            continue;
        vis[u.u] = true;
        for (int i = head[u.u]; ~i; i = e[i].next) {
            int v = e[i].v;
            if (disa[v] > disa[u.u] + e[i].w) {
                disa[v] = disa[u.u] + e[i].w;
                node w;
                w.dis = disa[v];
                w.u = v;
                q.push(w);
            }
        }
    }
}

void dijkstra_b() {
    priority_queue<node> q;
    disb[s] = 0;
    node st;
    st.dis = 0;
    st.u = s;
    q.push(st);
    while (!q.empty()) {
        node u = q.top();
        q.pop();
        if (vis[u.u])
            continue;
        vis[u.u] = true;
        for (int i = head[u.u]; ~i; i = e[i].next) {
            int v = e[i].v;
            if (disb[v] > disb[u.u] + e[i].w) {
                disb[v] = disb[u.u] + e[i].w;
                node w;
                w.dis = disb[v];
                w.u = v;
                q.push(w);
            }
        }
    }
}

void dijkstra_c() {
    priority_queue<node> q;
    disc[s] = 0;
    node st;
    st.dis = 0;
    st.u = s;
    q.push(st);
    while (!q.empty()) {
        node u = q.top();
        q.pop();
        if (vis[u.u])
            continue;
        vis[u.u] = true;
        for (int i = head[u.u]; ~i; i = e[i].next) {
            int v = e[i].v;
            if (disc[v] > disc[u.u] + e[i].w) {
                disc[v] = disc[u.u] + e[i].w;
                node w;
                w.dis = disc[v];
                w.u = v;
                q.push(w);
            }
        }
    }
}

int num[maxn], sum[maxn];

void solve() {
    memset(head, -1, sizeof(head));
    cnt = 0;
    int a, b, c;
    cin >> n >> m >> a >> b >> c;
    for (int i = 1; i <= m; ++i)
        cin >> num[i];
    sort(num + 1, num + 1 + m);
    for (int i = 1; i <= m; ++i)
        sum[i] = sum[i - 1] + num[i];
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        addedge(u, v, 1);
    }
    s = a;
    for (int i = 1; i <= n; ++i) {
        disa[i] = disb[i] = disc[i] = inf;
        vis[i] = false;
    }
    dijkstra_a();
    s = b;
    for (int i = 1; i <= n; ++i)
        vis[i] = false;
    dijkstra_b();
    s = c;
    for (int i = 1; i <= n; ++i)
        vis[i] = false;
    dijkstra_c();
    int ans = LLONG_MAX;
    for (int i = 1; i <= n; ++i) {
        int disai = disa[i];
        int disbi = disb[i];
        int disci = disc[i];
        if (disai + disbi + disci > m)
            continue;
        int now = sum[disai + disbi + disci] + sum[disbi];
        ans = min(ans, now);
    }
    cout << ans << '\n';
}

signed main() {
    start;
    cin >> T;
    while (T--)
        solve();
    return 0;
}