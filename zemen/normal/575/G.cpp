#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define forab(i,a,b) for (int i = int(a); i < int(b); ++i)

typedef long long ll;
typedef long double ld;

const int INF = 1000001000;
const ll INFL = 2000000000000001000;
int solve();

const int maxn = 100500;

int n, m;
vector<pair<int, int>> e[maxn];
int d[maxn];
int anc[maxn];
int q[maxn];
int b[maxn*10];
int ar[maxn*10];

void bfs(int s, bool fi) {
    forn(i, n) d[i] = INF;
    d[s] = 0;
    q[0] = s;
    int lq = 0, rq = 1;
    while (lq != rq) {
        int v = q[lq++];
        for (auto kv: e[v]) {
            int to = kv.first;
            if (fi && kv.second != 0) continue;
            if (d[to] > d[v] + 1) {
                d[to] = d[v] + 1;
                q[rq++] = to;
                if (fi) anc[to] = v;
            }
        }
    }
}

void scan() {
    scanf("%d%d", &n, &m);
    forn(i, m) {
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        e[u].push_back({v, c});
        e[v].push_back({u, c});
    }
}

void dfs(int v) {
    if (b[v] || v == 0) {
        return;
    }
    b[v] = 1;
    bool ok = false;
    for (auto kv: e[v]) {
        int to = kv.first;
        if (d[v] - 1 == d[to]) {
            dfs(to);
            if (d[to] != INF) ok = true;
        }
    }
    if (!ok) d[v] = INF;
}

vector<int> ng[20];

int solve()
{
    scan();
    string res;
    bfs(n-1, 1);
    vector<int> good;
    forn(i, n) if (d[i] != INF) good.push_back(i);
    sort(good.begin(), good.end(), [](int i, int j) { return d[i] < d[j]; });
//    cout << "first good: "; for (auto g: good) cout << g << " "; cout << endl;
    bfs(0, 0);
    int best = INF;
    for (auto g: good) best = min(best, d[g]);
    vector<int> ngood;
    for (auto g: good) if (d[g] == best) ngood.push_back(g);
    good = ngood;
//    cout << "filtr good: "; for (auto g: good) cout << g << " "; cout << endl;
    for (auto g: good) dfs(g);
//    forn(i, n) cout << d[i] << " "; cout << endl;
    memset(b, 0, sizeof b);

    forn(III, best) {
        forn(i, 10) ng[i].clear();
        for (auto v: good) {
            for (auto kv: e[v]) {
                int to = kv.first, c = kv.second;
                if (d[v] == d[to] + 1 && !b[to*10+c]) {
                    b[to*10+c] = 1;
                    ng[c].push_back(to);
                    ar[to*10+c] = v;
                }
            }
        }
        good.clear();
        forn(i, 10) if (!ng[i].empty()) {
            res += char('0'+i);
            good = ng[i];
            for (auto g: good) {
                anc[g] = ar[g*10+i];
            }
            break;
        }
        assert(!good.empty());
    }
    if (res.empty()) {
        printf("0\n");
    } else {
        printf("%s\n", res.c_str());
    }
    vector<int> cert;
    int v = 0;
    while (v != n-1) {
        v = anc[v];
        cert.push_back(v);
    }
    printf("%d\n", 1 + (int)cert.size());
    printf("0");
    for (auto x: cert) printf(" %d", x);
    printf("\n");
    return 0;
}

int main()
{
    srand(2317);
    cout.precision(10);
    cout.setf(ios::fixed);
    #ifdef LOCAL
    assert(freopen("g.in", "r", stdin));
    #else
    #endif
    int tn = 1;
    for (int i = 0; i < tn; ++i)
        solve();
    #ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
    #endif
}