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
    freopen("d.in", "r", stdin);
    #else
    #endif
    int tn = 1;
    for (int i = 0; i < tn; ++i)
        solve();
    #ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
    #endif
}

const int maxn = 2e6;

int z[maxn];
char s[maxn];
int delta[maxn];

int solve()
{
    int n, k;
    scanf("%d%d%s", &n, &k, s);
    int R = -1;
    int where = -1;
    z[0] = n;
    forn (i, n)
    {
        if (i == 0)
            continue;
        if (where > 0)
            z[i] = min(z[i - where], R - i);
        z[i] = max(z[i], 0);
        while (s[i + z[i]] == s[z[i]])
            ++z[i];
        if (i + z[i] > R)
            R = i + z[i], where = i;
        if (z[i] >= ll(i) * ll(k - 1))
        {
//            cerr << i * k - 1 << ' ' << min(i + z[i], i * k + i) << '\n';
            delta[i * k - 1]++;
            delta[min(i + z[i], i * k + i)]--;
        }
    }
    if (k == 1)
        delta[n - 1]++;
    int sum = 0;
    forn (i, n)
    {
        sum += delta[i];
        printf("%d", int(sum > 0));
    }
    printf("\n");
    return 0;
}