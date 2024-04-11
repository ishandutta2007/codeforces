#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

const int mod = 1e9 + 7;
void udd(int &a, int b) {
    a += b;
    if (a >= mod)
        a -= mod;
}
int mul(ll a, ll b) {
    return a * b % mod;
}

const int B = 35;
int ds[B+1][2][2][2];
ll dc[B+1][2][2][2];
int sk[B];
int sx[B];
int sy[B];

int ask(int x, int y, int k) {
    forn (i, B) {
        sk[i] = k % 2;
        k /= 2;
        sx[i] = x % 2;
        x /= 2;
        sy[i] = y % 2;
        y /= 2;
    }
    reverse(sk, sk + B);
    reverse(sx, sx + B);
    reverse(sy, sy + B);
    //forn (i, B)
        //cerr << sx[i];
    //cerr << '\n';
    //forn (i, B)
        //cerr << sy[i];
    //cerr << '\n';
    memset(ds, 0, sizeof(ds));
    memset(dc, 0, sizeof(dc));
    ds[0][1][1][1] = 0;
    dc[0][1][1][1] = 1;
    forn (i, B)
        forn (zk, 2)
            forn (zx, 2)
                forn (zy, 2) {
                    ll cnt = dc[i][zk][zx][zy];
                    int sum = ds[i][zk][zx][zy];
                    if (cnt == 0)
                        continue;
                    forn (dx, 2)
                        forn (dy, 2) {
                            if (dx > sx[i] && zx)
                                continue;
                            if (dy > sy[i] && zy)
                                continue;
                            if ((dx ^ dy) > sk[i] && zk)
                                continue;
                            bool nx = zx && dx == sx[i];
                            bool ny = zy && dy == sy[i];
                            bool nk = zk && (dx ^ dy) == sk[i];
                            int nsum = sum;
                            udd(nsum, nsum);
                            udd(nsum, mul(dx ^ dy, cnt % mod));
                            udd(ds[i + 1][nk][nx][ny], nsum);
                            dc[i + 1][nk][nx][ny] += cnt;
                        }
                }
    int res = ds[B][0][0][0];
    udd(res, dc[B][0][0][0] % mod);
    return res;
}

int que() {
    int x1, y1, x2, y2, k;
    cin >> x1 >> y1 >> x2 >> y2 >> k;
    --x1, --y1;
    int res = ask(x2, y2, k);
    udd(res, ask(x1, y1, k));
    udd(res, mod - ask(x2, y1, k));
    udd(res, mod - ask(x1, y2, k));
    return res;
}

int main() {
    #ifdef LOCAL
    assert(freopen("c.in", "r", stdin));
    #else
    #endif

    int q;
    cin >> q;
    forn (i, q) {
        cout << que() << '\n';
    }
}