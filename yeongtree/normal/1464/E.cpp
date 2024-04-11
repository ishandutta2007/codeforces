#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#define pii pair<int, int>
#define piii pair<int, pii>
#define pll pair<long long, long long>
#define plll pair<long long, pll>
#define ff first
#define ss second
#define ee ss.ff
#define rr ss.ss

using namespace std;

vector<int> gph[101010];
int in[101010];
int gr[101010];

const int MOD = 998'244'353;

inline int mpow(int a, int x)
{
    int ret = 1;
    while(x)
    {
        if(x & 1) ret = 1ll * ret * a % MOD;
        a = 1ll * a * a % MOD;
        x >>= 1;
    }
    return ret;
}

inline int rev(int x) { return mpow(x, MOD - 2); }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    for(int i = 0; i < m; ++i)
    {
        int x, y; cin >> x >> y; --x; --y;
        gph[x].push_back(y);
        ++in[y];
    }

    vector<int> T;
    queue<int> Q;
    for(int i = 0; i < n; ++i) if(!in[i]) Q.push(i);
    while(Q.size())
    {
        int t = Q.front(); Q.pop();
        T.push_back(t);
        for(auto i : gph[t]) if(!--in[i]) Q.push(i);
    }
    reverse(T.begin(), T.end());

    for(auto i : T)
    {
        vector<int> V;
        for(auto j : gph[i]) V.push_back(gr[j]);
        sort(V.begin(), V.end());
        V.resize(unique(V.begin(), V.end()) - V.begin());
        int pt = 0;
        for(auto j : V)
        {
            if(j == pt) ++pt;
            else break;
        }
        gr[i] = pt;
    }

//    for(int i = 0; i < n; ++i) cout << gr[i] << ' '; cout << endl;

    int q = 0; for(int i = 0; i < n; ++i) q = max(q, gr[i]);
    int k = 1; while(k <= q) k <<= 1;
    int X[k][k + 1]{};
    for(int i = 0; i < k; ++i) X[i][i] = n + 1;
    for(int i = 1; i < k; ++i) X[i][k] = 1;
    for(int i = 0; i < n; ++i) for(int j = 0; j < k; ++j) --X[j][j ^ gr[i]];
    for(int i = 0; i < k; ++i) for(int j = 0; j < k; ++j) if(X[i][j] < 0) X[i][j] += MOD;

    for(int i = k - 1; i >= 1; --i)
    {
        for(int j = 0; j < i; ++j)
        {
            int x = 1ll * rev(X[i][i]) * X[j][i] % MOD;
            for(int l = 0; l <= k; ++l) X[j][l] = (X[j][l] + MOD - 1ll * x * X[i][l] % MOD) % MOD;
        }
    }
    cout << 1ll * X[0][k] * rev(X[0][0]) % MOD;
    return 0;
}