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
#define TASK_LETTER "a"

#define STANDART_INPUT

#ifdef LOCAL
void initrand()
{
    ll seed;
    asm("rdtsc":"=A"(seed));
    srand(seed);
}
#endif

int m, k;
map<int, set<int> > friends;

void solve()
{
    cin >> m >> k;
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        friends[a].insert(b);
        friends[b].insert(a);
    }
    for (const auto &x: friends)
    {
        cout << x.first << ": ";
        vector<int> ans;
        for (const auto &y: friends)
        {
            if (x.first == y.first || x.second.count(y.first)) continue;
            vector<int> v(m);
            int s = set_intersection(all(x.second), all(y.second), v.begin()) - v.begin();
            if (s * 100 >= sz(x.second) * k)
                ans.pb(y.first);
        }
        cout << ans.size();
        for (int x : ans) cout << " " << x;
        cout << '\n';
    }
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