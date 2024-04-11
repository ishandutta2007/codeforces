#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

const int maxn = 1000100;
bool np[maxn];

void sito() {
    for (int i = 2; i < maxn; ++i) {
        if (!np[i])
            for (int j = 2 * i; j < maxn; j += i)
                np[j] = true;
    }
}

int main() {
    #ifdef LOCAL
    assert(freopen("b.in", "r", stdin));
    #else
    #endif
    sito();
    int n;
    cin >> n; 
    if (n < 3)
        cout << 1 << '\n';
    else
        cout << 2 << '\n';
    for (int i = 2; i <= n + 1; ++i) {
        if (np[i])
            cout << 2 << ' ';
        else
            cout << 1 << ' ';
    }
    cout << '\n';
}