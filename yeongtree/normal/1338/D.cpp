#include <iostream>
#include <algorithm>
#include <vector>
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
int ans;

pii dfs(int x, int p)
{
    int cnt = 0;
    int fmx = 0, fmx2 = 0;
    int smx = 0, smx2 = 0;
    for(auto y : gph[x])
    {
        if(y == p) continue;
        pii tmp = dfs(y, x);
        if(fmx2 < tmp.ff) swap(tmp.ff, fmx2);
        if(fmx < fmx2) swap(fmx, fmx2);
        if(smx2 < tmp.ss) swap(tmp.ss, smx2);
        if(smx < smx2) swap(smx, smx2);
        ++cnt;
    }

    ans = max(ans, smx + smx2 + max(cnt - 2, 0) + (x ? 1 : 0));
    ans = max(ans, fmx + fmx2 + 1);
    int f = smx + max(cnt - 1, 0);
    int s = fmx + 1;
    return {f, max(f, s)};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    for(int i = 1; i < n; ++i)
    {
        int x, y; cin >> x >> y; --x; --y;
        gph[x].push_back(y);
        gph[y].push_back(x);
    }

    dfs(0, -1);
    cout << ans;
}