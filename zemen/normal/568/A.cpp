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
    assert(freopen("a.in", "r", stdin));
    #else
    #endif
    int tn = 1;
    for (int i = 0; i < tn; ++i)
        solve();
    #ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
    #endif
}

const int BOUND = 4e6;

bool prime[BOUND];

char s[10];

bool ispal(int x)
{
    sprintf(s, "%d", x);
    int n = strlen(s);
    forn (i, n / 2)
        if (s[i] != s[n - 1 - i])
            return false;
    return true;
}

int solve()
{
    fill(prime, prime + BOUND, true);
    forab (i, 2, BOUND)
        if (prime[i])
            for (int j = 2 * i; j < BOUND; j += i)
                prime[j] = false;
    prime[1] = false;
    ll p, q;
    cin >> p >> q;
    int bestn = 1;
    int cpal = 0, cprime = 0;
    forab (i, 1, BOUND)
    {
        cpal += ispal(i);
        cprime += prime[i];
        if (cpal * p >= cprime * q)
            bestn = i;
    }
    cout << bestn << '\n';
    return 0;
}