#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <set>
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
        int n, m; cin >> n >> m;
        int X[n], Y[n]; long long a = 0, b = 0;
        for(auto &i : X) cin >> i;
        for(auto &i : Y) cin >> i;
        bool C[n + 1]{}; C[0] = true;
        for(int i = 0; i < n; ++i)
        {
            a += X[i], b += Y[i];
            if(a == b) C[i + 1] = true;
        }

        vector<pii> V;
        for(int i = 0; i < m; ++i)
        {
            int l, r; cin >> l >> r; --l;
            V.push_back({l, r});
        }
        for(int i = 0; i < n; ++i) V.push_back({i, i + 1});

        vector<int> ls[n + 1];
        for(int i = 0; i < n + m; ++i) ls[V[i].ff].push_back(i), ls[V[i].ss].push_back(i);

        vector<int> Q;
        set<int> S;
        for(int i = 0; i <= n; ++i) S.insert(i);
        for(int i = 0; i <= n; ++i) if(C[i]) Q.push_back(i), S.erase(i);

        int D[n + m]{};

        while(Q.size())
        {
            int x = Q.back(); Q.pop_back();
            for(auto y : ls[x]) if(++D[y] == 2)
            {
                for(auto it = S.lower_bound(V[y].ff); it != S.end() && *it < V[y].ss;)
                {
                    Q.push_back(*it);
                    it = S.erase(it);
                }
            }
        }

        cout << (S.empty() ? "YES\n" : "NO\n");
    }
}