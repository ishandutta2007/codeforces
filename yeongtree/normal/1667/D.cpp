#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#define pii pair<int, int>
#define piii pair<int, pii>
#define pll pair<long long, long long>
#define plll pair<long long, pll>
#define tiii tuple<int, int, int>
#define tiiii tuple<int, int, int, int>
#define ff first
#define ss second
#define ee ss.ff
#define rr ss.ss
#define DEBUG
const int INF = (int)1e9 + 7;

using namespace std;

vector<int> gph[202020];
bool E[202020];

bool f(int x, int p)
{
    int e = 0, o = 0;
    for(auto y : gph[x]) if(y != p)
    {
        if(!f(y, x)) return false;
        if(E[y]) ++e;
        else ++o;
    }

    if(p == -1)
    {
        if(e == o || e == o + 1) return true;
        return false;
    }
    else
    {
        if(e == o - 1 || e == o) { E[x] = true; return true; }
        if(e == o + 1 || e == o + 2) { E[x] = false; return true; }
        return false;
    }
}

void g(int x, int p)
{
    vector<int> o, e;
    for(auto y : gph[x])
    {
        if(y == p) y = x;
        if(E[y]) e.push_back(y);
        else o.push_back(y);
    }

    while(e.size())
    {
        if(e.size() > o.size())
        {
            int y = e.back(); e.pop_back();
            if(y == x) cout << p + 1 << ' ' << x + 1 << '\n';
            else g(y, x);
        }
        else
        {
            int y = o.back(); o.pop_back();
            if(y == x) cout << p + 1 << ' ' << x + 1 << '\n';
            else g(y, x);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        int n; cin >> n;
        for(int i = 0; i < n; ++i) gph[i].clear(), E[i] = false;
        for(int i = 1; i < n; ++i)
        {
            int x, y; cin >> x >> y; --x; --y;
            gph[x].push_back(y);
            gph[y].push_back(x);
        }

        if(!f(0, -1)) cout << "NO\n";
        else
        {
            cout << "YES\n";
            g(0, -1);
        }
    }
}