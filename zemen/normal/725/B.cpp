#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

map<char, int> conv;

int main() {
    #ifdef LOCAL
    assert(freopen("b.in", "r", stdin));
    #else
    #endif
    conv[int('f')] = 0;
    conv[int('e')] = 1;
    conv[int('d')] = 2;
    conv[int('a')] = 3;
    conv[int('b')] = 4;
    conv[int('c')] = 5;
    string s;
    cin >> s;
    char ch = s.back();
    s.pop_back();
    istringstream in(s);
    ll n;
    in >> n;
    --n;
    ll res = 16 * (n / 4);
    n %= 4;
    if (n == 1 || n == 3)
        res += 7;
    res += conv[ch];
    cout << res + 1 << '\n';
}