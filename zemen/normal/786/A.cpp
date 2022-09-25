#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

vector<int> v[2];

const int maxn = 15010;
int d[maxn];
int deg[maxn];
int n;

bool inq[maxn];
vector<pair<int, int>> q;

void put(int x, int val) {
    d[x] = val;
    int who = x & 1;
    //cerr << x / 2 << ' ' << who << ' ' << val << '\n';
    for (int delta: v[who ^ 1]) {
        int from = x / 2 - delta;
        if (from < 0)
            from += n;
        int u = from * 2 + !who;
        if (inq[u])
            continue;
        if (val == 0) {
            inq[u] = true;
            q.emplace_back(u, 1);
        } else if (--deg[u] == 0) {
            inq[u] = true;
            q.emplace_back(u, 0);
        }
    }
}

int main() {
    #ifdef LOCAL
    assert(freopen("a.in", "r", stdin));
    #else
    #endif
    int k1, k2;
    cin >> n >> k1;
    forn (i, k1) {
        int x;
        cin >> x;
        v[0].push_back(x);
    }
    cin >> k2;
    forn (i, k2) {
        int x;
        cin >> x;
        v[1].push_back(x);
    }
    forn (i, n * 2)
        d[i] = -1;
    q.emplace_back(0, 0);
    q.emplace_back(1, 0);
    inq[0] = inq[1] = true;

    forn (i, n) {
        deg[i * 2] = k1;
        deg[i * 2 + 1] = k2;
    }
    forn (i, sz(q))
        put(q[i].first, q[i].second);
    
    forn (qq, 2) {
        for (int i = 1; i < n; ++i) {
            int x = d[i * 2 + qq];
            if (x == -1)
                cout << "Loop";
            else if (x == 1)
                cout << "Win";
            else if (x == 0)
                cout << "Lose";
            else
                assert(false);
            cout << ' ';
        }
        cout << '\n';
    }
}