#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int par[303030];
bool same[303030];
int on[303030];
int off[303030];
int ans;
const int MAX = 1e8;

int fnd(int x)
{
    if(x == par[x]) return x;
    int y = fnd(par[x]);
    same[x] = (same[x] == same[par[x]]);
    return par[x] = y;
}

void unon(int);
void unoff(int);
void uni0(int, int);
void uni1(int, int);

void unon(int x)
{
    int _x = fnd(x);
    if(!same[x]) { unoff(_x); return; }
    x = _x;

    ans -= min(on[x], off[x]);
    off[x] = MAX;
    ans += on[x];
}
void unoff(int x)
{
    int _x = fnd(x);
    if(!same[x]) { unon(_x); return; }
    x = _x;

    ans -= min(on[x], off[x]);
    on[x] = MAX;
    ans += off[x];
}
void uni0(int x, int y)
{
    int _x = fnd(x), _y = fnd(y);
    if(_x == _y) return;
    if(same[x] != same[y]) { uni1(_x, _y); return; }
    x = _x; y = _y;

    ans -= min(on[x], off[x]);
    ans -= min(on[y], off[y]);

    par[y] = x; same[y] = false;
    on[x] += off[y]; if(on[x] > MAX) on[x] = MAX;
    off[x] += on[y]; if(off[x] > MAX) off[x] = MAX;

    ans += min(on[x], off[x]);
}
void uni1(int x, int y)
{
    int _x = fnd(x), _y = fnd(y);
    if(_x == _y) return;
    if(same[x] != same[y]) { uni0(_x, _y); return; }
    x = _x; y = _y;

    ans -= min(on[x], off[x]);
    ans -= min(on[y], off[y]);

    par[y] = x; same[y] = true;
    on[x] += on[y]; if(on[x] > MAX) on[x] = MAX;
    off[x] += off[y]; if(off[x] > MAX) off[x] = MAX;

    ans += min(on[x], off[x]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;
    string s; cin >> s;

    vector<int> inp[n];
    for(int i = 0; i < k; ++i)
    {
        int m; cin >> m;
        for(int j = 0; j < m; ++j)
        {
            int x; cin >> x; --x;
            inp[x].push_back(i);
        }
    }
    for(int i = 0; i < k; ++i) par[i] = i, on[i] = 1, same[i] = true;

    for(int i = 0; i < n; ++i)
    {
        if(s[i] == '0' && inp[i].size() == 1) unon(inp[i][0]);
        else if(s[i] == '0' && inp[i].size() == 2) uni0(inp[i][0], inp[i][1]);
        else if(s[i] == '1' && inp[i].size() == 1) unoff(inp[i][0]);
        else if(s[i] == '1' && inp[i].size() == 2) uni1(inp[i][0], inp[i][1]);
        cout << ans << '\n';
    }
}