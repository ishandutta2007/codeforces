#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define forab(i,a,b) for (int i = int(a); i < int(b); ++i)

typedef long long ll;
typedef long long i64;
typedef long double ld;

const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

const int maxn = 1100100;

vector<int> all;
vector<int> ts[maxn];

struct Fenwick {
    vector<int> t;

    Fenwick() {
    }

    Fenwick(int n) {
        t = vector<int>(n, 0);
    }

    void put(int x, int delta) {
        for (int i = x; i < sz(t); i |= i + 1)
            t[i] += delta;
    }

    int get(int r) {
        int res = 0;
        for (int i = r - 1; i >= 0; i = (i & (i + 1)) - 1)
            res += t[i];
        return res;
    }
};

Fenwick fw[maxn];

struct Event {
    int a, t, x;
};

Event e[maxn];

int main() {
    cout.precision(10);
    cout.setf(ios::fixed);
    #ifdef LOCAL
    assert(freopen("e.in", "r", stdin));
    #else
    #endif
    int n;
    scanf("%d", &n);
    forn (i, n) {
        int a, t, x;
        scanf("%d%d%d", &a, &t, &x);
        all.push_back(x);
        e[i] = Event{a, t, x};
    }
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());
    forn (i, n) {
        e[i].x = lower_bound(all.begin(), all.end(), e[i].x) - all.begin();
        ts[e[i].x].push_back(e[i].t);
    }
    forn (i, sz(all)) {
        sort(ts[i].begin(), ts[i].end());
        fw[i] = Fenwick(sz(ts[i]));
    }
    forn (i, n) {
        e[i].t = lower_bound(ts[e[i].x].begin(), ts[e[i].x].end(), e[i].t) - ts[e[i].x].begin();
        if (e[i].a == 1)
            fw[e[i].x].put(e[i].t, 1);
        else if (e[i].a == 2)
            fw[e[i].x].put(e[i].t, -1);
        else if (e[i].a == 3)
            cout << fw[e[i].x].get(e[i].t) << '\n';
        else
            assert(false);
    }

    #ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
    #endif
}