#include <bits/stdc++.h>
using namespace std;
#define INF int(1e9+1)
#define INFL ll(2e18+INF)
#define sz(x) ((int) (x).size())
typedef long long ll;
typedef long double ld;
typedef complex <ld> point;
void solve();

#define NAME "d"
#define LOCAL_INPUT NAME ".in"
//~ #define LOCAL_OUTPUT NAME ".out"
//~ #define INPUT NAME ".in"
//~ #define OUTPUT NAME ".out"

int main() {
    srand(time(0));
    cout.setf(ios::fixed);
    cout.precision(10);
    #ifdef _GEANY
        clock_t start = clock();
        #ifdef LOCAL_INPUT
            assert(freopen(LOCAL_INPUT, "r", stdin));
        #endif
        #ifdef LOCAL_OUTPUT
            assert(freopen(LOCAL_OUTPUT, "w", stdout));
        #endif
    #else
        #ifdef INPUT
            assert(freopen(INPUT, "r", stdin));
        #endif
        #ifdef OUTPUT
            assert(freopen(OUTPUT, "w", stdout));
        #endif
    #endif
    int tn = 1;
    for (int i = 0; i < tn; ++i)
        solve();
    #ifdef _GEANY
        fprintf(stderr, "Time: %.3fs\n", double(clock() - start) / CLOCKS_PER_SEC);
    #endif
}

vector <int> g[100001];

const ll mod = 1000000007;

inline void add(ll &a, ll b) {
    a += b;
    a %= mod;
}

pair <ll, ll> dfs(int u) {
    sort(g[u].begin(), g[u].end());
    ll res[2][2][2];
    memset(res, 0, sizeof(res));
    res[1][0][0] = 1;
    for (int i = 0; i < sz(g[u]); ++i) {
        pair <ll, ll> c = dfs(g[u][i]);
        ll even = c.first;
        ll odd = c.second;
        //~ cerr << "son " << even << ' ' << odd << '\n';
        ll cres[2][2][2];
        for (int sum = 0; sum < 2; ++sum)
            for (int was_odd = 0; was_odd < 2; ++was_odd)
                for (int was_even = 0; was_even < 2; ++was_even)
                    cres[sum][was_odd][was_even] = res[sum][was_odd][was_even];
        //~ cerr << "was even " << res[0][0][1] + res[1][0][1] << '\n';
        //~ cerr << "was odd " << res[0][1][0] + res[1][1][0] << '\n';
        for (int sum = 0; sum < 2; ++sum)
            for (int was_odd = 0; was_odd < 2; ++was_odd)
                for (int was_even = 0; was_even < 2; ++was_even) {
                    add(res[sum ^ 1][1][was_even], odd * cres[sum][was_odd][was_even]);
                    add(res[sum][was_odd][1], even * cres[sum][was_odd][was_even]);
                }
    }
    for (int sum = 0; sum < 2; ++sum)
        for (int was_odd = 0; was_odd < 2; ++was_odd)
            for (int was_even = 0; was_even < 2; ++was_even) {
                if ((was_odd && sum == 1) || (was_even && sum == 0))
                    add(res[sum][was_odd][was_even], res[sum][was_odd][was_even]);
            }
    ll odd = 0, even = 0;
    for (int was_odd = 0; was_odd < 2; ++was_odd)
        for (int was_even = 0; was_even < 2; ++was_even) {
            add(odd, res[1][was_odd][was_even]);
            add(even, res[0][was_odd][was_even]);
        }
    return make_pair(even, odd);
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int p;
        cin >> p;
        --p;
        g[p].push_back(i + 1);
    }
    pair <ll, ll> res = dfs(0);
    cout << (res.first + res.second) % mod << '\n';
}