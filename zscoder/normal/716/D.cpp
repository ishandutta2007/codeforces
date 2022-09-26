#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m, need, s, t;
vector<PII> g[1000];
int eu[30000], ev[30000], len[30000];
vector<int> zero;
const int INF = 1e9 + 123;
const LL LINF = 1e18;

LL dist[1000];

struct Cmp {
    inline bool operator()(const int &lhs, const int &rhs) const {
        if (dist[lhs] != dist[rhs]) return dist[lhs] < dist[rhs];
        return lhs < rhs;
    }
};

set<int, Cmp> q;

LL dij() {
    forn(i, n) {
        dist[i] = LINF;
    }
    dist[s] = 0;
    q.insert(s);
    while (!q.empty()) {
        int v = *q.begin();
        q.erase(q.begin());
        for (PII to : g[v]) if (dist[to.first] > dist[v] + len[to.second]) {
            q.erase(to.first);
            dist[to.first] = dist[v] + len[to.second];
            q.insert(to.first);
        }
    }
    return dist[t];
}

void out() {
    printf("YES\n");
    forn(i, m) {
        printf("%d %d %d\n", eu[i], ev[i], len[i]);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d%d%d%d%d", &n, &m, &need, &s, &t);
    forn(i, m) {
        int from, to, w;
        scanf("%d%d%d", &from, &to, &w);
        eu[i] = from;
        ev[i] = to;
        len[i] = w;
        g[from].pb(mp(to, i));
        g[to].pb(mp(from, i));
        if (w == 0) {
            zero.pb(i);
        }
    }

    for (int x : zero) {
        len[x] = INF;
    }
    LL cur = dij();
    if (cur < need) {
        cout << "NO" << endl;
        return 0;
    }
    if (cur == need) {
        out();
        return 0;
    }

    for (int x : zero) {
        len[x] = 1;
    }
    cur = dij();
    if (cur > need) {
        cout << "NO" << endl;
        return 0;
    }
    if (cur == need) {
        out();
        return 0;
    }

    int lo = 1, hi = (int)zero.size();
    while (lo < hi) {
        int mid = (lo + hi) >> 1;
        forn(i, mid) {
            len[zero[i]] = 1;
        }
        for (int i = mid; i < (int)zero.size(); ++i) {
            len[zero[i]] = INF;
        }
        if (dij() <= need) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    forn(i, lo) {
        len[zero[i]] = 1;
    }
    for (int i = lo; i < (int)zero.size(); ++i) {
        len[zero[i]] = INF;
    }
    int ind = lo - 1;
    lo = 1, hi = INF;
    while (lo < hi) {
        int mid = (lo + hi) >> 1;
        len[zero[ind]] = mid;
        if (dij() < need) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    len[zero[ind]] = lo;
    out();
    return 0;
}