#include <iostream>
#include <vector>
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

const int MAX = 2e6;
struct eg
{
    int y, a, b;
    bool val;
    eg *ot;
};
vector<eg*> gph[MAX];
int prog[MAX];

void dfs(int x)
{
    while(prog[x] < gph[x].size())
    {
        eg *y = gph[x][prog[x]++];
        if(y->val)
        {
            y->val = false;
            y->ot->val = false;
            dfs(y->y);
            cout << y->b + 1 << ' ' << y->a + 1 << ' ';
        }
    }
}

int par[MAX];
int fnd(int x) { return (x == par[x] ? x : par[x] = fnd(par[x])); }
void uni(int x, int y) { par[fnd(x)] = fnd(y); }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    pii arr[n]; for(auto &i : arr) cin >> i.ff >> i.ss;
    int cnt[MAX];

    int s = 0, e = 21;
    while(s + 1 < e)
    {
        int mid = s + e >> 1;
        int mx = 1 << mid, msk = mx - 1;
        for(int i = 0; i < mx; ++i) cnt[i] = 0;
        for(int i = 0; i < n; ++i) ++cnt[arr[i].ff & msk], ++cnt[arr[i].ss & msk];
        bool flag = true;
        for(int i = 0; i < mx; ++i) if(cnt[i] & 1) flag = false;
        for(int i = 0; i < mx; ++i) par[i] = i;
        for(int i = 0; i < n; ++i) uni(arr[i].ff & msk, arr[i].ss & msk);
        int acnt = 0;
        for(int i = 0; i < mx; ++i) if(cnt[i] && i == fnd(i)) ++acnt;
        if(acnt >= 2) flag = false;
        if(flag) s = mid;
        else e = mid;
    }

    int mask = (1 << s) - 1;
    for(int i = 0; i < n; ++i)
    {
        int xx = arr[i].ff & mask;
        int yy = arr[i].ss & mask;
        auto xit = new eg({xx, 2 * i + 1, 2 * i, true, nullptr});
        auto yit = new eg({yy, 2 * i, 2 * i + 1, true, nullptr});
        xit->ot = yit;
        yit->ot = xit;
        gph[xx].push_back(yit);
        gph[yy].push_back(xit);
    }

    cout << s << '\n';
    for(int i = 0; i < (1 << s); ++i)
    {
        if(gph[i].size() >= 1)
        {
            dfs(i);
            return 0;
        }
    }
}