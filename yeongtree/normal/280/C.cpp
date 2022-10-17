#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <iomanip>
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

vector<int> gph[101010];

long double ans = 0;
void dfs(int x, int p, int d)
{
    ans += 1.0l / d;
    for(auto y : gph[x]) if(y != p) dfs(y, x, d + 1);
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

    dfs(0, 0, 1);
    cout << fixed << setprecision(20) << ans;
}