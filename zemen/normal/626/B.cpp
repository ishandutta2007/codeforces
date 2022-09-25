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

int solve()
{
    int n;
    string s;
    cin >> n >> s;
    map<char, int> cnt;
    forn (i, n)
        cnt[s[i]]++;
    if (cnt['R'] && cnt['G'] && cnt['B'])
    {
        cout << "BGR\n";
        return 0;
    }
    if (cnt['G'] == 0 && cnt['B'] == 0)
    {
        cout << "R\n";
        return 0;
    }
    if (cnt['G'] == 0 && cnt['R'] == 0)
    {
        cout << "B\n";
        return 0;
    }
    if (cnt['R'] == 0 && cnt['B'] == 0)
    {
        cout << "G\n";
        return 0;
    }
    if (n == 2)
    {
        if (cnt['R'] == 0)
        {
            cout << "R\n";
            return 0;
        }
        if (cnt['G'] == 0)
        {
            cout << "G\n";
            return 0;
        }
        if (cnt['B'] == 0)
        {
            cout << "B\n";
            return 0;
        }
        assert(false);
    }
    if (cnt['R'] == n - 1)
    {
        cout << "BG\n";
        return 0;
    }
    if (cnt['G'] == n - 1)
    {
        cout << "BR\n";
        return 0;
    }
    if (cnt['B'] == n - 1)
    {
        cout << "GR\n";
        return 0;
    }
    cout << "BGR\n";
    return 0;
}