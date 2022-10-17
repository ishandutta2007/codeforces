#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
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
const int INF = (int)1e9 + 7;

using namespace std;

vector<int> gph[202020];
vector<int> chd[202020];
vector<pii> qr;
int in[202020];
int out[202020];
int dep[202020];
int cnt = 0;
int par[202020];
int ps[202020];
int fnd(int x) { return (par[x] == x ? x : par[x] = fnd(par[x])); }
void uni(int x, int y) { par[fnd(y)] = fnd(x); }

void dfs(int x, int p, int d)
{
    in[x] = cnt++;
    dep[x] = d;
    vector<int> tmp;
    for(auto y : gph[x]) if(y != p) dfs(y, x, d + 1), tmp.push_back(y);
    gph[x] = tmp;
    out[x] = cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for(int i = 0; i < 202020; ++i) par[i] = i;
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; ++i)
    {
        int x, y; cin >> x >> y; --x; --y;
        if(fnd(x) == fnd(y)) qr.push_back({x, y});
        else uni(x, y), gph[x].push_back(y), gph[y].push_back(x);
    }

    dfs(0, 0, 0);
    for(int i = 0; i < n; ++i) for(auto x : gph[i]) chd[i].push_back(out[x]);
//    for(int i = 0; i < n; ++i) cout << out[i] << ' '; cout << endl;
//    for(int i = 0; i < n; ++i)
//    {
//        for(auto x : chd[i]) cout << x << ' ';
//        cout << endl;
//    }

    for(auto [x, y] : qr)
    {
        if(dep[x] > dep[y]) swap(x, y);
        if(in[x] <= in[y] && out[y] <= out[x])
        {
            int z = lower_bound(chd[x].begin(), chd[x].end(), out[y]) - chd[x].begin();
            z = gph[x][z];
            ++ps[0];
            --ps[in[z]];
            ++ps[out[z]];
            ++ps[in[y]];
            --ps[out[y]];
        }
        else
        {
            ++ps[in[x]];
            --ps[out[x]];
            ++ps[in[y]];
            --ps[out[y]];
        }
    }

    for(int i = 1; i < 202020; ++i) ps[i] += ps[i - 1];
    for(int i = 0; i < n; ++i) cout << (ps[in[i]] == (int)qr.size() ? 1 : 0);
}