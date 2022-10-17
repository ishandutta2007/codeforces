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

    int T; cin >> T;
    while(T--)
    {
        int n, k; cin >> n >> k;
        bool A[n * 2]{};
        vector<pii> V;
        for(int i = 0; i < k; ++i)
        {
            int x, y; cin >> x >> y; --x; --y;
            if(x > y) swap(x, y);
            A[x] = true;
            A[y] = true;
            V.push_back({x, y});
        }
        V.resize(n);

        int cnt = 0;
        for(int i = 0; i < 2 * n; ++i) if(!A[i])
        {
            if(cnt < n - k)
            {
                V[cnt + k].ff = i;
            }
            else
            {
                V[cnt - n + 2 * k].ss = i;
            }
            ++cnt;
        }

        int ans = 0;
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < i; ++j)
            {
                int t = 0;
                if(V[i].ff < V[j].ff && V[j].ff < V[i].ss) ++t;
                if(V[i].ff < V[j].ss && V[j].ss < V[i].ss) ++t;
                if(t == 1) ++ans;
            }
        }
        cout << ans << '\n';
    }
}