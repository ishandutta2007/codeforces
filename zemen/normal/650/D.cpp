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

const int maxn = 400400;
int h[maxn];
int qa[maxn], qb[maxn];
vector<int> qid[maxn];
int qans[maxn];

int d[maxn], f[maxn];

int dpos[maxn], dold[maxn];

int ANS;
int goods = 0;

bool isGood(int i) {
    return d[i] < -f[ANS - i];
}

void rewind(int i) {
    goods -= isGood(dpos[i]);
    d[dpos[i]] = dold[i];
    goods += isGood(dpos[i]);
}

int get() {
    if (goods > 0)
        return ANS;
    return ANS - 1;
}

int main() {
    cout.precision(10);
    cout.setf(ios::fixed);
    #ifdef LOCAL
    assert(freopen("d.in", "r", stdin));
    #else
    #endif
    int n, m;
    cin >> n >> m;
    forn (i, n) {
        scanf("%d", &h[i]);
    }
    forn (i, m) {
        scanf("%d%d", &qa[i], &qb[i]);
        --qa[i];
        qid[qa[i]].push_back(i);
    }

    forn (i, n + 1)
        d[i] = f[i] = inf;
    f[0] = d[0] = -inf;
    forn (i, n) {
        int pos = dpos[i] = lower_bound(d, d + n + 1, h[i]) - d;
        dold[i] = d[pos];
        d[pos] = h[i];
        ANS = max(ANS, pos);
    }
    //cerr << "ans " << ANS << '\n';
    forn (i, n + 1)
        goods += isGood(i);

    for (int i = n - 1; i >= 0; --i) {
        rewind(i);

        for (int id: qid[i]) {
            int lend = lower_bound(d, d + n + 1, qb[id]) - d - 1;
            int lenf = lower_bound(f, f + n + 1, -qb[id]) - f - 1;
            qans[id] = max(lend + lenf + 1, get());
        }

        int pos = lower_bound(f, f + n + 1, -h[i]) - f;
        goods -= isGood(ANS - pos);
        f[pos] = -h[i];
        goods += isGood(ANS - pos);
    }

    forn (i, m)
        cout << qans[i] << '\n';

    #ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
    #endif
}