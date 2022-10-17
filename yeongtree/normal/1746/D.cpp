#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <tuple>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define piii pair<int, pii>
#define plll pair<long long, pll>
#define tiii tuple<int, int, int>
#define tiiii tuple<int, int, int, int>
#define ff first
#define ss second
#define ee ss.ff
#define rr ss.ss

using namespace std;

int A[202020];
vector<int> gph[202020];
pll dfs(int x, int k)
{
    if(gph[x].size() == 0) return { 1ll * k * A[x], 1ll * (k + 1) * A[x] };
    vector<pll> V;
    for(auto y : gph[x]) V.push_back(dfs(y, k / (int)gph[x].size()));
    sort(V.begin(), V.end(), [](pll x, pll y) { return x.ss - x.ff > y.ss - y.ff; });

    long long ret = 0;
    for(auto [x, y] : V) ret += x;
    int n = k - (k / (int)gph[x].size()) * (int)gph[x].size();
    for(int i = 0; i < n; ++i) ret += V[i].ss - V[i].ff;
    return { 1ll * k * A[x] + ret, 1ll * (k + 1) * A[x] + ret + V[n].ss - V[n].ff };
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        int n, k; cin >> n >> k;
        for(int i = 0; i < n; ++i) gph[i].clear();
        for(int i = 1; i < n; ++i)
        {
            int p; cin >> p; --p;
            gph[p].push_back(i);
        }
        for(int i = 0; i < n; ++i) cin >> A[i];
        cout << dfs(0, k).ff << '\n';
    }
}