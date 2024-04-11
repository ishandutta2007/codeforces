#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define forab(i,a,b) for (int i = int(a); i < int(b); ++i)

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
    assert(freopen("b.in", "r", stdin));
    #else
    #endif
    int tn = 1;
    for (int i = 0; i < tn; ++i)
        solve();
    #ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
    #endif
}

void process(char *s, int n)
{
    if (n % 2)
        return;
    process(s, n / 2);
    process(s + n / 2, n / 2);
    bool ok = false;
    forn (i, n / 2)
        if (s[i] > s[i + n / 2])
        {
            ok = true;
            break;
        }
        else if (s[i] < s[i + n / 2])
            break;
    if (ok)
    {
        forn (i, n / 2)
            swap(s[i], s[i + n / 2]);
    }
}

char s[2][300005];

int solve()
{
    scanf("%s%s", s[0], s[1]);
    process(s[0], strlen(s[0]));
    process(s[1], strlen(s[1]));
    if (strcmp(s[0], s[1]) == 0)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}