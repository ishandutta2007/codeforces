#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long i64;
typedef unsigned long long u64;
typedef long double ld;
typedef long long ll;

int n, k, l;
string s;
int p;

vector<string> res;

void solve() {
    --k;
    res.resize(n);
    sort(all(s));
    int b = 0;
    for (int pos = 0; pos < l; ++pos) {
        // cerr << pos << " " << b << "\n";
        for (int b2 = b; b2 <= k; ++b2) {
            res[b2].push_back(s[p++]);
        }
        while (res[b][pos] != res[k][pos]) ++b;
    }
    forn(i, n) {
        while ((int)res[i].size() < l) {
            res[i].push_back(s[p++]);
        }
    }
    forn(i, n) {
        cout << res[i] << "\n";
    }
}

int main() {
#ifdef LOCAL
    freopen("l.in", "r", stdin);
#endif

    ios::sync_with_stdio(false);

    cin >> n >> l >> k >> s;
    solve();


#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}