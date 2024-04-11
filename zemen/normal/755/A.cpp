#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

const int maxn = 2e6;
bool np[maxn];

int main() {
    #ifdef LOCAL
    assert(freopen("a.in", "r", stdin));
    #else
    #endif
    for (int i = 2; i < maxn; ++i)
        if (!np[i])
            for (int j = i * 2; j < maxn; j += i)
                np[j] = true;
    int n;
    cin >> n;
    for (int i = 1; ; ++i) {
        int x = n * i + 1;
        if (np[x]) {
            cout << i << '\n';
            break;
        }
    }
}