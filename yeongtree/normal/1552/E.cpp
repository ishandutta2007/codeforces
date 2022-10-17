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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;
    vector<int> ls[n];
    for(int i = 0; i < n * k; ++i)
    {
        int x; cin >> x; --x;
        ls[x].push_back(i);
    }

    for(int i = 0; i < n; i += k - 1)
    {
        bool chc[k - 1]{};
        pii ans[k - 1];
        for(int j = 0; j < k - 1 && i + j < n; ++j)
        {
            int id = -1;
            for(int l = 0; l < k - 1 && i + l < n; ++l)
                if(!chc[l] && (id == -1 || ls[i + l][j + 1] < ls[i + id][j + 1])) id = l;
            chc[id] = true;
            ans[id] = { ls[i + id][j] + 1, ls[i + id][j + 1] + 1 };
        }
        for(int j = 0; j < k - 1 && i + j < n; ++j) cout << ans[j].ff << ' ' << ans[j].ss << '\n';
    }
}