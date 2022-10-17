#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
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

int val[202020];
int inv[202020];
vector<pii> gph;
vector<pii> qr;
priority_queue<int, vector<int>, greater<int>> pq[202020];
vector<int> ls[202020];
vector<pii> par[202020];

int fnd(int x) { return par[x].back().ff; }
void uni(int x, int y, int i)
{
    x = fnd(x), y = fnd(y);
    if(x != y)
    {
        if(ls[x].size() < ls[y].size()) swap(x, y);
        for(auto j : ls[y])
        {
            ls[x].push_back(j);
            par[j].push_back({x, i});
        }
        ls[y].clear(); ls[y].shrink_to_fit();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, T; cin >> n >> m >> T;
    for(int i = 0; i < n; ++i) cin >> val[i], par[i].push_back({i, T}), --val[i], ls[i].push_back(i);
    for(int i = 0; i < n; ++i) inv[val[i]] = i;
    for(int i = 0; i < m; ++i)
    {
        int x, y; cin >> x >> y; --x; --y;
        gph.push_back({x, y});
    }
    bool chc[m]{}; int cnt = 0;
    for(int i = 0; i < T; ++i)
    {
        int x, y; cin >> x >> y; --y;
        qr.push_back({x, y});
        if(x == 2) chc[y] = true;
    }
    for(int i = 0; i < m; ++i) if(!chc[i]) uni(gph[i].ff, gph[i].ss, T);

    int ans[T]{};
    for(int i = T - 1; i >= 0; --i)
    {
        if(qr[i].ff == 1)
        {
            int x = fnd(qr[i].ss);
            pq[x].push(i);
        }
        else
        {
            uni(gph[qr[i].ss].ff, gph[qr[i].ss].ss, i);
        }
    }

    for(int i = n - 1; i >= 0; --i)
    {
        int x = inv[i];
        for(int j = (int)par[x].size() - 1; j >= 0; --j)
        {
            if(pq[par[x][j].ff].size() && pq[par[x][j].ff].top() < par[x][j].ss)
            {
                ans[pq[par[x][j].ff].top()] = i + 1;
                pq[par[x][j].ff].pop();
                break;
            }
        }
    }

    for(int i = 0; i < T; ++i) if(qr[i].ff == 1) cout << ans[i] << '\n';
}