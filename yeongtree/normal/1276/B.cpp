#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define pii pair<int, int>
#define piii pair<pii, int>
#define pll pair<long long, long long>
#define ff first
#define ss second

using namespace std;

vector<int> gph[202020];
int vst[202020];
int cnt;

inline long long comb2(int x) {return (long long)x * (x - 1) / 2;}

void dfs(int x)
{
    vst[x] = cnt;
    for(auto y : gph[x]) if(!vst[y]) dfs(y);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        int n, m, a, b; cin >> n >> m >> a >> b; --a; --b;

        for(int i = 0; i < m; ++i)
        {
            int x, y; cin >> x >> y; --x; --y;
            gph[x].push_back(y);
            gph[y].push_back(x);
        }

        long long ans = comb2(n - 2);
        pii cmp[n];

        for(int i = 0; i < n; ++i) vst[i] = 0;
        vst[a] = -1; cnt = 1;
        for(int i = 0; i < n; ++i) if(!vst[i]) dfs(i), ++cnt;
        for(int i = 0; i < n; ++i) cmp[i].ff = vst[i];
        vst[b] = -2;
        sort(vst, vst + n);
        int pprv = -1, con = 1;
        for(int i = 0; i < n; ++i)
        {
            if(pprv == vst[i]) ++con;
            else ans -= comb2(con), pprv = vst[i], con = 1;
        }
        ans -= comb2(con);

        for(int i = 0; i < n; ++i) vst[i] = false;
        vst[b] = -1; cnt = 1;
        for(int i = 0; i < n; ++i) if(!vst[i]) dfs(i), ++cnt;
        for(int i = 0; i < n; ++i) cmp[i].ss = vst[i];
        vst[a] = -2;
        sort(vst, vst + n);
        pprv = -1; con = 1;
        for(int i = 0; i < n; ++i)
        {
            if(pprv == vst[i]) ++con;
            else ans -= comb2(con), pprv = vst[i], con = 1;
        }
        ans -= comb2(con);

        sort(cmp, cmp + n);

        pii prv = {-1, -1}; con = 1;
        for(int i = 0; i < n; ++i)
        {
            if(prv == cmp[i]) ++con;
            else ans += comb2(con), prv = cmp[i], con = 1;
        }
        ans += comb2(con);

        cout << ans << '\n';

        for(int i = 0; i < n; ++i) vector<int>().swap(gph[i]);
    }
}