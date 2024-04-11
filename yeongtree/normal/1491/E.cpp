#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define piii pair<int, pii>
#define plll pair<long long, pll>
#define ff first
#define ss second
#define tiii tuple<int, int, int>
#define tiiii tuple<int, int, int, int>
#define tlll tuple<long long, long long, long long>
#define tllll tuple<long long, long long, long long, long long>
#define DEBUG

using namespace std;

vector<int> gph[202020];
bool chc[202020];
int par[202020];
int sz[202020];
int F[30];

int dfs(int x, int lv)
{
    sz[x] = 1;
    for(auto y : gph[x]) if(!chc[y])
    {
        int t = dfs(y, lv);
        if(t != -1) return t;
        sz[x] += sz[y];
    }
    if(sz[x] == F[lv - 1] || sz[x] == F[lv - 2]) return x;
    return -1;
}

bool sol(int x, int lv)
{
    if(lv == 0 || lv == 1) return true;

    int t = dfs(x, lv);
    if(t == -1) return false;
    chc[t] = true;
    if(sz[t] == F[lv - 1]) return sol(t, lv - 1) && sol(x, lv - 2);
    else return sol(t, lv - 2) && sol(x, lv - 1);
}

void mktree(int x, int p)
{
    par[x] = p;
    vector<int> tmp;
    for(auto y : gph[x]) if(y != p)
    {
        tmp.push_back(y);
        mktree(y, x);
    }
    gph[x].swap(tmp);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    F[0] = F[1] = 1;
    for(int i = 2; i < 30; ++i) F[i] = F[i - 1] + F[i - 2];

    int n; cin >> n;
    for(int i = 1; i < n; ++i)
    {
        int x, y; cin >> x >> y; --x; --y;
        gph[x].push_back(y);
        gph[y].push_back(x);
    }
    mktree(0, 0);

    for(int i = 0; i < 30; ++i) if(n == F[i])
    {
        if(sol(0, i)) cout << "YES";
        else cout << "NO";
        return 0;
    }

    cout << "NO";
    return 0;
}