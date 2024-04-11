#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

/*
typedef pair<int, ll> State;
map<State, int> gr;

int calc(State s) {
    if (gr.count(s))
        return gr[s];
    vector<int> v(s.first + 1);
    for (int i = 1; i <= s.first; ++i) {
        if (s.second & (1ll << i))
            continue;
        State to{s.first - i, s.second | (1 << i)};
        int g = calc(to);
        if (g < sz(v))
            v[g] = 1;
    }
    int res = 0;
    while (v[res])
        ++res;
    return gr[s] = res;
}
*/

int gr[61] = {
    0, 1, 1, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10
};

int main() {
    #ifdef LOCAL
    assert(freopen("e.in", "r", stdin));
    #else
    #endif
    //forn (i, 61) {
        //cerr << calc({i, 0}) << ", ";
    //}
    //cerr << '\n';
    int n;
    cin >> n;
    int x = 0;
    forn (i, n) {
        int s;
        scanf("%d", &s);
        x ^= gr[s];
    }
    cout << (x ? "NO\n" : "YES\n");
}