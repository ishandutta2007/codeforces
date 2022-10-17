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
const int INF = 998'244'353;

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        int n, m; cin >> n >> m;
        int A[n]; for(auto &i : A) cin >> i;
        vector<int> gph[n];
        int in[n]{};
        for(int i = 0; i < m; ++i)
        {
            int x, y; cin >> x >> y; --x; --y;
            gph[x].push_back(y);
            ++in[y];
        }
        vector<int> Q;
        for(int i = 0; i < n; ++i) if(in[i] == 0) Q.push_back(i);

        int B[n]{};
        bool D[n]{};
        vector<pii> C[n];

        while(Q.size())
        {
            int x = Q.back(); Q.pop_back();
            if(A[x]) C[x].push_back({0, A[x]});
            sort(C[x].begin(), C[x].end());

            if(C[x].size())
            {
                vector<pii> T;
                auto [l, r] = C[x].front();
                for(int i = 1; i < (int)C[x].size(); ++i)
                {
                    auto [p, q] = C[x][i];
                    if(p <= r) r += q - p;
                    else { T.push_back({l, r}), l = p, r = q; }
                }
                if(r > 1000) B[x] = (B[x] + r - 1000) % INF, r = 1000, D[x] = true;
                T.push_back({l, r});
                C[x] = T;
            }


            for(auto y : gph[x])
            {
                B[y] = (B[x] + B[y]) % INF;
                if(D[x]) D[y] = true;
                for(auto i : C[x]) C[y].push_back({i.ff + 1, i.ss + 1});
                if(!--in[y]) Q.push_back(y);
            }
        }

        for(int i = 0; i < n; ++i) if(gph[i].size() == 0)
        {
            if(D[i]) cout << (B[i] + 1000) % INF << '\n';
            else if(C[i].size()) cout << C[i].back().ss << '\n';
            else cout << 0 << '\n';
        }
    }
}