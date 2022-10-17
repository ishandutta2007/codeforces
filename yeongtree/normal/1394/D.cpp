#include <iostream>
#include <vector>
#include <algorithm>
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

const long long INF = (long long)8e18;
int t[202020];
int h[202020];
vector<int> gph[202020];

pll dfs(int x, int p, bool root)
{
    pll ret = {INF, INF};
    vector<long long> A;
    long long cost = 0;
    int a = 0, b = 0, c = 0;

    for(auto y : gph[x]) if(y != p)
    {
        if(h[x] < h[y]) cost += dfs(y, x, false).ff, ++a;
        else if(h[x] > h[y]) cost += dfs(y, x, false).ss, ++b;
        else
        {
            pll tmp = dfs(y, x, false);
            cost += tmp.ff;
            A.push_back(tmp.ss - tmp.ff);
            ++c;
        }
    }
    sort(A.begin(), A.end());

    if(!root)
    {
        for(int i = 0; i <= c; ++i)
        {
            ret.ff = min(ret.ff, cost + 1ll * t[x] * max(a + c - i, b + i + 1));
            ret.ss = min(ret.ss, cost + 1ll * t[x] * max(a + c - i + 1, b + i));
            if(i < c) cost += A[i];
        }
        return ret;
    }
    else
    {
        for(int i = 0; i <= c; ++i)
        {
            ret.ff = min(ret.ff, cost + 1ll * t[x] * max(a + c - i, b + i));
            if(i < c) cost += A[i];
        }
        return ret;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    for(int i = 0; i < n; ++i) cin >> t[i];
    for(int i = 0; i < n; ++i) cin >> h[i];
    for(int i = 1; i < n; ++i)
    {
        int x, y; cin >> x >> y; --x; --y;
        gph[x].push_back(y);
        gph[y].push_back(x);
    }

    cout << dfs(0, -1, true).ff;
}