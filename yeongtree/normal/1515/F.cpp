#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <queue>
#define pii pair<int, int>
#define piii pair<int, pii>
#define pll pair<long long, long long>
#define plll pair<long long, pll>
#define tiii tuple<int, int, int>
#define tiiii tuple<int, int, int, int>
#define ff first
#define ss second
#define ee ss.ff
#define rr ss.ss
#define DEBUG

using namespace std;

long long X;
long long A[303030];
vector<pii> gph[303030];
vector<pii> eg;
vector<int> ans;

int par[303030];
int fnd(int x) { return x == par[x] ? x : par[x] = fnd(par[x]); }
void uni(int x, int y)
{
    x = fnd(x); y = fnd(y);
    if(x == y) return;
    if(gph[x].size() < gph[y].size()) swap(gph[x], gph[y]);
    for(auto i : gph[y]) gph[x].push_back(i);
    vector<pii>().swap(gph[y]);
    A[x] += A[y] - X;
    A[y] = 0;
    par[y] = x;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m >> X;
    for(int i = 0; i < n; ++i) cin >> A[i];
    for(int i = 0; i < m; ++i)
    {
        int x, y; cin >> x >> y; --x; --y;
        gph[x].push_back({y, i});
        gph[y].push_back({x, i});
        eg.push_back({x, y});
    }
    for(int i = 0; i < n; ++i) par[i] = i;

    priority_queue<pll> Q;
    for(int i = 0; i < n; ++i) Q.push({A[i], i});
    while(Q.size() && Q.top().ff >= X)
    {
        int x = Q.top().ss; Q.pop();
        if(!A[x]) continue;
        while(gph[x].size())
        {
            if(fnd(x) != fnd(gph[x].back().ff))
            {
                ans.push_back(gph[x].back().ss);
                uni(x, gph[x].back().ff);
                break;
            }
            gph[x].pop_back();
        }
        if(gph[x].size()) Q.push({A[x], x});
    }

    vector<pll> V;
    for(int i = 0; i < m; ++i)
    {
        if(fnd(eg[i].ff) != fnd(eg[i].ss))
        {
            V.push_back({ A[fnd(eg[i].ff)] + A[fnd(eg[i].ss)], i });
        }
    }
    sort(V.begin(), V.end());
    for(auto [x, i] : V)
    {
        if(fnd(eg[i].ff) != fnd(eg[i].ss) && A[fnd(eg[i].ff)] + A[fnd(eg[i].ss)] >= X)
        {
            ans.push_back((int)i);
            uni(eg[i].ff, eg[i].ss);
        }
    }

    if((int)ans.size() == n - 1)
    {
        cout << "YES\n";
        for(auto i : ans) cout << i + 1 << '\n';
    }
    else cout << "NO\n";
}