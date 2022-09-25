#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

const int maxn = 105;
int p[maxn];

bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y';
}

int main() {
    #ifdef LOCAL
    assert(freopen("b.in", "r", stdin));
    #else
    #endif
    int n;
    cin >> n;
    forn (i, n)
        scanf("%d", p + i);
    scanf(" ");
    forn (i, n) {
        string s;
        getline(cin, s);
        int cnt = 0;
        for (auto c: s)
            cnt += isVowel(c);
        if (cnt != p[i]) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
}