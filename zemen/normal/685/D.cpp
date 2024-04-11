#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

const int maxn = 100100;
const int maxc = 100100 * 302;
int cnt[maxc];
int ycoord[maxc];
pair<pair<int, int>, bool> qq[maxn * 2];
ll ans[maxn];

int main() {
    #ifdef LOCAL
    assert(freopen("d.in", "r", stdin));
    #else
    #endif
    int n, k;
    cin >> n >> k;
    cnt[0] = n;
    int ycc = 0, qcc = 0;
    forn (i, n) {
        int x, y;
        scanf("%d%d", &x, &y);
        forn (j, k + 1)
            ycoord[ycc++] = y - j;
        qq[qcc++] = make_pair(make_pair(x - k, y), false);
        qq[qcc++] = make_pair(make_pair(x, y), true);
    }
    sort(ycoord, ycoord + ycc);
    ycc = unique(ycoord, ycoord + ycc) - ycoord;
    sort(qq, qq + qcc);
    forn (qid, qcc) {
        auto q = qq[qid];
        int x = q.first.first, y = q.first.second;
        bool close = q.second;
        int iy = lower_bound(ycoord, ycoord + ycc, y) - ycoord;
        for (int i = iy; i > iy - k; --i) {
            ans[cnt[i]] += x;
            if (close) {
                cnt[i]--;
            } else {
                cnt[i]++;
            }
            ans[cnt[i]] -= x;
        }
    }
    for (int i = 1; i <= n; ++i)
        cout << ans[i] << ' ';
    cout << '\n';
}