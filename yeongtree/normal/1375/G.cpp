#include <iostream>
#include <vector>

using namespace std;

vector<int> gph[202020];

int dfs(int x, int p, bool flag)
{
    int ret = (flag ? 1 : 0);
    for(auto y : gph[x]) if(y != p) ret += dfs(y, x, !flag);
    return ret;
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

    int x = dfs(0, -1, true);
    cout << min(x, n - x) - 1;
}