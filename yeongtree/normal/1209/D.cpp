#include <iostream>
#include <vector>

using namespace std;

vector<int> gph[101010];
bool visit[101010];

int dfs(int x)
{
    visit[x] = true;
    int ret = 1;
    for(auto i : gph[x])
        if(!visit[i]) ret += dfs(i);
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;
    for(int i = 0; i < k; ++i)
    {
        int x, y; cin >> x >> y; --x; --y;
        gph[x].push_back(y);
        gph[y].push_back(x);
    }

    int ans = 0;
    for(int i = 0; i < n; ++i)
        if(!visit[i]) ans += dfs(i) - 1;

    cout << (k >= ans ? k - ans : 0);
    return 0;
}