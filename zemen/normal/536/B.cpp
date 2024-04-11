#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())
#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; --i)

typedef long long ll;
typedef long double ld;

const int INF = 1000001000;
const ll INFL = 2000000000000001000;
int solve();


int main()
{
    srand(2317);
    cout.precision(10);
    cout.setf(ios::fixed);
    #ifdef LOCAL
    freopen("b.in", "r", stdin);
    #else
    #endif
    int tn = 1;
    for (int i = 0; i < tn; ++i)
        solve();
    #ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
    #endif
}

const int maxn = 4000001;
char s[maxn];
int pi[maxn];
int delta[maxn];
bool inter[maxn];

int solve()
{
    int n, m;
    cin >> n >> m;
    scanf("%s", s);
    int len = strlen(s);
    int k = 0;
    forn (i, len)
    {
        if (i == 0)
            continue;
        while (k > 0 && s[k] != s[i])
            k = pi[k - 1];
        if (s[k] == s[i])
            ++k;
        pi[i] = k;
    }
    while (k)
    {
        inter[k] = true;
        k = pi[k - 1];
    }
    int pr = -1e9;
    bool ok = true;
    forn (i, m)
    {
        int pos;
        scanf("%d", &pos);
        --pos;
        if (pr + len > pos && !inter[len - pos + pr])
            ok = false;
        delta[pos]++;
        delta[pos + len]--;
        pr = pos;
    }
    if (!ok)
    {
        cout << 0 << '\n';
        return 0;
    }
    int sum = 0;
    ll ans = 1;
    forn (i, n)
    {
        sum += delta[i];
        if (!sum)
            ans = (ans * 26) % 1000000007;
    }
    cout << ans << '\n';
    return 0;
}