#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

vector<int> g[10000];
int ord[10000];

vector<int> mem[10000];
int qs = 0;
bool FLAG;

vector<int> ask(int u) {
    if (!mem[u].empty())
        return mem[u];
    ++qs;
    if (qs > 16) {
        cout << "! " << u << endl;
        FLAG = true;
        return {-1};
    }
    cout << "? " << u << endl;
#ifdef LOCAL
    vector<int> res = g[u];
    int k = sz(res);
#else
    int k;
    cin >> k;
    vector<int> res(k);
    forn (i, k)
        cin >> res[i];
#endif
    mem[u] = res;
    if (k == 2) {
        cout << "! " << u << endl;
        FLAG = true;
        return {-1};
    }
    return res;
}

int go(int u, int bad = -1) {
    if (FLAG)
        return -1;
    auto nx = ask(u);
    if (FLAG)
        return -1;

    int v = nx[0];
    if (v == bad && sz(nx) == 1)
        return -1;
    if (v == bad)
        return nx[1];
    return v;
}

vector<int> getPath() {
    int u = 1;

    vector<int> res;
    int pr = -1;
    while (u != -1) {
        res.push_back(u);

        int to = go(u, pr);
        if (FLAG)
            return {-1};
        pr = u;
        u = to;
    }

    if (sz(ask(1)) > 1) {
        int bad = res[1];
        reverse(res.begin(), res.end());
        u = go(1, bad);
        if (FLAG)
            return {-1};
        pr = 1;

        while (u != -1) {
            res.push_back(u);

            int to = go(u, pr);
            if (FLAG)
                return {-1};
            pr = u;
            u = to;
        }
    }
    return res;
}

bool brute(int u, int bad, int d) {
    if (FLAG)
        return true;
    auto nx = ask(u);
    if (FLAG)
        return true;

    if (d == 0)
        return false;
    for (int v: nx) {
        if (v == bad)
            continue;
        if (brute(v, u, d - 1))
            return true;
    }
    return false;
}

void solve(int h) {
    qs = 0;
    forn (i, 1 << h)
        mem[i].clear();
    FLAG = false;

    auto path = getPath();
    if (FLAG)
        return;
    //for (int x: path)
        //cerr << x << ' ';
    //cerr << '\n';
    
    assert(sz(path) % 2 == 1);
    int u = path[sz(path) / 2];
    vector<int> nx = ask(u);
    if (FLAG)
        return;
    nx.erase(find(nx.begin(), nx.end(), path[sz(path) / 2 - 1]));
    nx.erase(find(nx.begin(), nx.end(), path[sz(path) / 2 + 1]));
    assert(sz(nx) == 1);
    int bad = u;
    u = nx[0];
    int ch = sz(path) / 2 + 1;

    while (ch < 4) {
        int v = u;
        int pr = bad;
        vector<int> cp;
        forn (iter, ch) {
            cp.push_back(v);

            int to = go(v, pr);
            if (FLAG)
                return;
            pr = v;
            v = to;
        }
        cp.push_back(v);

        int to = cp[1];
        nx = ask(u);
        if (FLAG)
            return;
        nx.erase(find(nx.begin(), nx.end(), bad));
        if (sz(ask(v)) == 1) {
            nx.erase(find(nx.begin(), nx.end(), cp[1]));
            assert(sz(nx) == 1);
            to = nx[0];
        }

        bad = u;
        u = to;
        ++ch;
    }

    brute(u, bad, h - ch - 1);
}

void addEdge(int u, int v) {
    g[u].push_back(v);
    g[v].push_back(u);
}

int main() {
    #ifdef LOCAL
    assert(freopen("f.in", "r", stdin));
    #else
    #endif
    int t;
    cin >> t;
    forn (ii, t) {
        int h;
        cin >> h;
#ifdef LOCAL
        forn (i, 1 << h)
            g[i].clear();
        forn (i, 1 << h)
            sort(g[i].begin(), g[i].end());
        for (int i = 1; i < (1 << h); ++i) {
            cin >> ord[i];
            if (i > 1)
                addEdge(ord[i], ord[i / 2]);
        }
#endif
        solve(h);
    }
}