#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
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

const int Q = (int)1e9 + 7;
const int mask[5] = {31, 31 << 5, 31 << 10, 31 << 15, 31 << 20};
vector<pii> gph[101010];
int dep[101010];
pii sp[17][101010];

int conv(int x, int y)
{
    if(x == -1 || y == -1) return -1;

    int bs[5]; for(int i = 0; i < 5; ++i) bs[i] = (mask[i] & x) >> (i * 5);

    for(int i = 0; i < 5; ++i)
    {
        int t = (mask[i] & y) >> (i * 5);
        if(t)
        {
            for(int j = i; j < 5; ++j)
                t = min(t, t ^ bs[j]);
            if(!t) return -1;

            for(int j = 0; j < 5; ++j)
                bs[j] = min(bs[j], t ^ bs[j]);

            for(int j = 1; j <= 5; ++j) if(!(t >> j))
            {
                bs[5 - j] = t;
                break;
            }
        }
    }

    int ret = 0;
    for(int i = 0; i < 5; ++i) ret |= (bs[i] << (i * 5));
    return ret;
}

int dfs(int x)
{
//    cout << endl;
    for(int i = 1; i < 17; ++i)
    sp[i][x] = { sp[i - 1][sp[i - 1][x].ff].ff, sp[i - 1][x].ss ^ sp[i - 1][sp[i - 1][x].ff].ss };

    int ret = 0;
    for(auto &y : gph[x])
    {
        if(y.ff == sp[0][x].ff) continue;
        if(!dep[y.ff])
        {
            sp[0][y.ff] = {x, y.ss}; dep[y.ff] = dep[x] + 1;
//            cout << x << ' ' << y.ff << ' ' << ret << endl;
            ret = conv(ret, dfs(y.ff));
//            cout << x << ' ' << y.ff << ' ' << ret << endl;
        }
        else if(dep[y.ff] != 2 && x < y.ff)
        {
            int a = x, b = y.ff;
            if(dep[a] < dep[b]) swap(a, b);
            int cost = y.ss;
            for(int i = 16; i >= 0; --i) if(dep[a] - (1 << i) >= dep[b])
                cost ^= sp[i][a].ss, a = sp[i][a].ff;
            for(int i = 16; i >= 0; --i) if(sp[i][a].ff != sp[i][b].ff)
                cost ^= sp[i][a].ss ^ sp[i][b].ss, a = sp[i][a].ff, b = sp[i][b].ff;
            if(a != b) cost ^= sp[0][a].ss ^ sp[0][b].ss;

            if(!cost) return -1;
            for(int i = 1; i <= 5; ++i) if(!(cost >> i))
            {
                ret = conv(ret, cost << (5 * (5 - i)));
                break;
            }
//            cout << x << ' ' << y.ff << ' ' << cost << ' ' << ret << endl;
        }
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    for(int i = 0; i < m; ++i)
    {
        int s, e, x; cin >> s >> e >> x; --s; --e;
        gph[s].push_back({e, x});
        gph[e].push_back({s, x});
    }

    int N = gph[0].size();
    pii arr[N]{};

    dep[0] = 1;
    for(int i = 0; i < N; ++i) dep[gph[0][i].ff] = 2, sp[0][gph[0][i].ff] = {0, gph[0][i].ss};
    for(int i = 0; i < N; ++i) arr[i].ff = dfs(gph[0][i].ff);

    int flag[n]{}; for(auto &i : flag) i = -1;
    for(int i = 0; i < N; ++i)
    {
        if(flag[gph[0][i].ff] != -1)
        {
            int j = flag[gph[0][i].ff];
            arr[j].ff = conv(arr[j].ff, arr[i].ff);
            arr[j].ss = conv(arr[j].ff, arr[j].ss);
        }
        if(dep[gph[0][i].ff] == 2)
        {
            for(auto &j : gph[gph[0][i].ff]) if(dep[j.ff] == 2)
            {
                dep[j.ff] = 0;
                flag[j.ff] = i;
                int cost = sp[0][gph[0][i].ff].ss ^ sp[0][j.ff].ss ^ j.ss;
                if(!cost) arr[i].ss = -1;
                else arr[i].ss = cost;
            }
        }
    }

    unordered_map<int, int> UM, __UM;
    UM[0] = 1; __UM[0] = 1;
    for(int i = 0; i < N; ++i) if(dep[gph[0][i].ff] == 2)
    {
        if(arr[i].ss)
        {
            for(auto &j : UM)
            {
                int t = conv(j.ff, arr[i].ff);
                int s = conv(j.ff, arr[i].ss);
                if(t != -1) __UM[t] += j.ss * 2 % Q, __UM[t] %= Q;
                if(s != -1) __UM[s] += j.ss, __UM[s] %= Q;
            }
        }
        else
        {
            for(auto &j : UM)
            {
                int t = conv(j.ff, arr[i].ff);
                if(t != -1) __UM[t] += j.ss, __UM[t] %= Q;
            }
        }
        UM = __UM;
    }

    int ans = 0;
    for(auto &i : __UM) ans = (ans + i.ss) % Q;
    cout << ans;
    return 0;
}