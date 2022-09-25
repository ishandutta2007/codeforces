#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

const int maxn = 300300;
vector<int> v[maxn];
int p[maxn];

vector<pair<int, int>> all;
int allp;

int main() {
    #ifdef LOCAL
    assert(freopen("a.in", "r", stdin));
    #else
    #endif
    int n, q;
    cin >> n >> q;
    int ans = 0;
    forn (i, q) {
        int t, x;
        scanf("%d%d", &t, &x);
        if (t == 1) {
            ++ans;
            all.emplace_back(x, v[x].size());
            v[x].push_back(1);
        } else if (t == 2) {
            for (int &i = p[x]; i < sz(v[x]); ++i) {
                ans -= v[x][i];
                v[x][i] = 0;
            }
        } else {
            for (int &i = allp; i < min(sz(all), x); ++i) {
                int id = all[i].first;
                int pos = all[i].second;
                ans -= v[id][pos];
                v[id][pos] = 0;
            }
        }
        cout << ans << '\n';
    }
}