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

const int maxn = 200200;
struct T {
    int p, a, b;
};

T a[maxn];
int n;
int p[5];
bool bad[maxn];

int main() {
    #ifdef LOCAL
    assert(freopen("b.in", "r", stdin));
    #else
    #endif
    cin >> n;
    forn (i, n)
        scanf("%d", &a[i].p);
    forn (i, n)
        scanf("%d", &a[i].a);
    forn (i, n)
        scanf("%d", &a[i].b);
    sort(a, a + n, [] (const T &a, const T &b) {
                return a.p < b.p;
            });
    int m;
    cin >> m;
    forn (ii, m) {
        int c;
        scanf("%d", &c);
        int &x = p[c];
        while (x < n && (bad[x] || (a[x].a != c && a[x].b != c)))
            ++x;
        if (x == n) {
            cout << -1 << ' ';
            continue;
        }
        bad[x] = true;
        cout << a[x].p << ' ';
    }
    cout << '\n';
}