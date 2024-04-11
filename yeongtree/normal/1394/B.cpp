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

vector<pii> in[202020];
vector<pii> out[202020];
vector<pii> gph[10][10];
int ans = 0;

void dfs(vector<int> &arr, int lv, int k)
{
    for(auto x : gph[lv][arr[lv]]) if(arr[x.ff] == x.ss) return;
    if(lv == k) { ++ans; return; }
    ++lv;
    for(int i = 0; i < lv; ++i)
    {
        arr[lv] = i;
        dfs(arr, lv, k);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k; cin >> n >> m >> k;

    for(int i = 0; i < m; ++i)
    {
        int s, e, x; cin >> s >> e >> x; --s; --e;
        out[s].push_back({x, e});
    }

    for(int i = 0; i < n; ++i)
    {
        sort(out[i].begin(), out[i].end());
        for(int j = 0; j < (int)out[i].size(); ++j)
        {
            in[out[i][j].ss].push_back({out[i].size(), j});
        }
    }

    for(int i = 0; i < n; ++i)
    {
        sort(in[i].begin(), in[i].end());
        vector<pii> tmp;
        for(int j = 0; j < (int)in[i].size(); ++j)
        {
            if(j == (int)in[i].size() - 1 || in[i][j] != in[i][j + 1])
                tmp.push_back(in[i][j]);
            else
            {
                gph[in[i][j].ff][in[i][j].ss].push_back(in[i][j]);
                while(j != (int)in[i].size() - 1 && in[i][j] == in[i][j + 1]) ++j;
            }
        }
        for(int j = 0; j < (int)tmp.size(); ++j)
        {
            for(int k = 0; k < (int)tmp.size(); ++k)
            {
                if(tmp[j].ff > tmp[k].ff) gph[tmp[j].ff][tmp[j].ss].push_back(tmp[k]);
            }
        }
    }

    for(int i = 1; i <= k; ++i)
    {
        for(int j = 0; j < i; ++j)
        {
            sort(gph[i][j].begin(), gph[i][j].end());
            gph[i][j].erase(unique(gph[i][j].begin(), gph[i][j].end()), gph[i][j].end());
        }
    }

    vector<int> arr(k + 1);
    dfs(arr, 1, k);
    cout << ans;
}