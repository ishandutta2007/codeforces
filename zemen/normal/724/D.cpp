#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

int n, m;
string s;
int cnt[1000];

bool check(char last) {
    int cur = 0;
    forn (i, n) {
        if (s[i] > last)
            ++cur;
        else
            cur = 0;
        if (cur >= m)
            return false;
    }
    return true;
}

int solve(char c) {
    int res = 0;
    int cur = 0;
    forn (i, n) {
        if (s[i] >= c)
            ++cur;
        else if (s[i] < c)
            cur = 0;
        if (cur == m) {
            int j;
            for (j = i; s[j] != c; --j);
            ++res;
            cur = i - j;
        }
    }
    return res;
}

int main() {
    #ifdef LOCAL
    assert(freopen("d.in", "r", stdin));
    #else
    #endif
    cin >> m >> s;
    n = sz(s);
    forn (i, n)
        cnt[int(s[i])]++;
    string res;
    for (char c = 'a'; c <= 'z'; ++c) {
        if (!check(c)) {
            forn (i, cnt[int(c)])
                res.push_back(c);
            continue;
        }
        int x = solve(c);
        forn (i, x)
            res.push_back(c);
        break;
    }
    cout << res << '\n';
}