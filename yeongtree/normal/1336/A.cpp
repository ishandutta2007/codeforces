#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> gph[202020];
vector<int> V;

int dfs(int x, int p, int d)
{
    int sz = 0;
    for(auto y : gph[x])
    {
        if(y == p) continue;
        sz += dfs(y, x, d + 1);
    }
    V.push_back(sz - d);
    return sz + 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;
    for(int i = 1; i < n; ++i)
    {
        int x, y; cin >> x >> y; --x; --y;
        gph[x].push_back(y);
        gph[y].push_back(x);
    }

    dfs(0, -1, 0);
    sort(V.rbegin(), V.rend());

    long long ans = 0;
    for(int i = 0; i < n - k; ++i) ans += V[i];
    cout << ans;
    return 0;
}