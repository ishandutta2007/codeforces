#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> gph[202020];
bool chc[202020];

int dfs(int x)
{
    if(chc[x]) return x;

    chc[x] = true;
    int ret = x;
    for(auto i : gph[x])
        ret = max(ret, dfs(i));

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    for(int i = 0; i < m; ++i)
    {
        int x, y; cin >> x >> y; --x; --y;
        gph[x].push_back(y);
        gph[y].push_back(x);
    }

    int ans = 0, f = -1;
    for(int i = 0; i < n; ++i)
        if(!chc[i])
    {
        if(i < f) ++ans;
        f = max(f, dfs(i));
    }

    cout << ans;
    return 0;
}