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
#define TASK_LETTER "f"

#define STANDART_INPUT

const ll mul[2] = {28981, 9394911};
const ll mod[2] = {1000000007, 1000000009};
const int alph = 26;
const int maxn = 300000;

int n, m, match[alph];
string s[2];
pair< pair<ll, ll>, int> u[maxn][alph], w[alph];

void solve()
{
    cin >> n >> m >> s[0] >> s[1];
    for (int c = 0; c < alph; ++c)
    {
        ll h1 = 0, h2 = 0, p1 = 1, p2 = 1;
        pair<ll, ll> q = mp(0, 0);
        for (int i = 0; i < m; ++i)
        {
            int ch = (s[0][i] - 'a' == c) ? 1 : 0;
            h1 = (h1 * mul[0] + ch) % mod[0];
            h2 = (h2 * mul[1] + ch) % mod[1];
            p1 = p1 * mul[0] % mod[0];
            p2 = p2 * mul[1] % mod[1];

            int d = (s[1][i] - 'a' == c) ? 1 : 0;
            q.first = (q.first * mul[0] + d) % mod[0];
            q.second = (q.second * mul[1] + d) % mod[1];
        }
        w[c] = mp(q, c);
        for (int i = 0; i + m <= n; ++i)
        {
            u[i][c] = mp(mp(h1, h2), c);

            if (i + m < n)
            {
                int add = (s[0][i + m] - 'a' == c) ? 1 : 0;
                h1 = (h1 * mul[0] + add) % mod[0];
                h2 = (h2 * mul[1] + add) % mod[1];
            }

            int del = (s[0][i] - 'a' == c) ? 1 : 0;
            h1 = (h1 - p1 * del) % mod[0];
            if (h1 < 0) h1 += mod[0];
            h2 = (h2 - p2 * del) % mod[1];
            if (h2 < 0) h2 += mod[1];
        }
    }
    sort(w, w + alph);
    int sz = 0;
    while (w[sz].first.first == 0 && w[sz].first.second == 0)
        sz++;

//     for (int i = sz; i < alph; ++i)
//         cerr << w[i].first.first << " " << w[i].first.second << " " << char('a' + w[i].second) << endl;
//     cerr << endl;

    vector<int> ans;
    for (int i = 0; i + m <= n; ++i)
    {
        sort(u[i], u[i] + alph);

//         for (int j = sz; j < alph; ++j)
//             cerr << u[i][j].first.first << " " << u[i][j].first.second << " " << char('a' + u[i][j].second) << endl;
//         cerr << endl;

        bool ok = true;
        for (int j = 0; j < alph; ++j)
            match[j] = -1;
        for (int j = sz; j < alph; ++j)
        {
            ok &= w[j].first == u[i][j].first;
            match[w[j].second] = u[i][j].second;
        }
        if (ok)
            for (int j = 0; j < alph; ++j)
                ok &= match[j] == -1 || match[match[j]] == -1 || match[match[j]] == j;
        if (ok)
            ans.pb(i);
    }
    cout << ans.size() << endl;
    for (int x : ans) cout << x + 1 << " ";
    cout << endl;
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