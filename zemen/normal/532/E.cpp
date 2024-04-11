#define y1 JulioCortasar
#define y2 GabrielGarsiaMarkes
#include <bits/stdc++.h>
#undef y1
#undef y2

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 42
#endif

#define pb push_back
#define mp make_pair
#define sz(v) ((int) (v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef double lf;

const ll inf = 1e9 + 100500;

#define TASK_NAME "INSERT_TASK_NAME_HERE"
#define TASK_LETTER "e"

#define STANDART_INPUT

#ifdef LOCAL
void initrand()
{
    ll seed;
    asm("rdtsc":"=A"(seed));
    srand(seed);
}
#endif

const int maxn = 100000;
const int mod1 = 1000000007;
const int mod2 = 1000000009;
const int mult1 = 84921;
const int mult2 = 48391;

int get(const string &s, const string &t)
{
    for (int i = 0; i < sz(s); ++i)
        if (s[i] != '?' && t[i] != '?' && s[i] != t[i])
            return 0;
    return 1;
}

void solve()
{
    int n;
    string s, t;
    cin >> n >> s >> t;
    int lcp = 0, lcs = 0;
    while (lcp < n && s[lcp] == t[lcp]) ++lcp;
    while (lcs < n && s[n - 1 - lcs] == t[n - 1 - lcs]) ++lcs;
    s = s.substr(lcp, n - lcp - lcs);
    t = t.substr(lcp, n - lcp - lcs);
    cout << get('?' + s, t + '?') + get(s + '?', '?' + t) << endl;
}

int main()
{
#ifdef LOCAL
    freopen(TASK_LETTER ".in", "r", stdin);
#else
#ifndef STANDART_INPUT
    freopen(TASK_NAME ".in", "r", stdin);
    freopen(TASK_NAME ".out", "w", stdout);
#endif
#endif
    solve();
#ifdef LOCAL
    cerr << "Time = " << clock() / 1000 << " ms." << endl;
#endif
	return 0;
}