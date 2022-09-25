#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())

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
	freopen("a.in", "r", stdin);
	#else
	#endif
	int tn = 1;
	for (int i = 0; i < tn; ++i)
		solve();
	#ifdef LOCAL
	cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
	#endif
}

vector <int> g[100];
string s[1001];
string ord;
bool used[100];

void dfs(int u)
{
    used[u] = true;
    for (auto v: g[u])
    {
        if (!used[v])
            dfs(v);
    }
    ord += char(u + 'a');
}

int solve()
{
	int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> s[i];
    for (int i = 0; i < n - 1; ++i)
    {
        int minp = -1;
        for (int j = 0; j < min(sz(s[i]), sz(s[i + 1])); ++j)
            if (s[i][j] != s[i + 1][j])
                minp = j, j = 1000000;
        if (minp == -1)
        {
            if (sz(s[i]) > sz(s[i + 1]))
            {
                cout << "Impossible\n";
                return 0;
            }
            continue;
        }
        g[s[i][minp] - 'a'].push_back(s[i + 1][minp] - 'a');
    }
    for (int i = 0; i < 26; ++i)
        if (!used[i])
            dfs(i);
    reverse(ord.begin(), ord.end());
//    cerr << ord << '\n';
    for (int i = 0; i < n - 1; ++i)
    {
        int minp = -1;
        for (int j = 0; j < min(sz(s[i]), sz(s[i + 1])); ++j)
            if (s[i][j] != s[i + 1][j])
                minp = j, j = 1000000;
        if (minp == -1)
        {
            if (sz(s[i]) > sz(s[i + 1]))
            {
                cout << "Impossible\n";
                return 0;
            }
            continue;
        }
        int p1 = 0, p2 = 0;
        while (ord[p1] != s[i][minp])
            ++p1;
        while (ord[p2] != s[i + 1][minp])
            ++p2;
        if (p1 > p2)
        {
            cout << "Impossible\n";
            return 0;
        }
    }
    cout << ord << '\n';

	return 0;
}