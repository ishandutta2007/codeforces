#include <iostream>
#include <vector>

using namespace std;

vector<int> gph[101010];
bool chc[101010];
int l = 1, r = -1;

bool dfs(int x, int p)
{
    if(gph[x].size() == 1)
    {
        if(!chc[p]) ++r;
        chc[p] = true;
        return false;
    }

    ++r;
    bool ret = false;
    bool two = false;
    for(auto y : gph[x])
    {
        if(y == p) continue;
        if(dfs(y, x)) two = true;
        else ret = true;
    }

    if(ret && two) l = 3;
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

    for(int i = 0; i < n; ++i)
    {
        if(gph[i].size() >= 2)
        {
            dfs(i, -1);
            break;
        }
    }

    cout << l << ' ' << r;
}