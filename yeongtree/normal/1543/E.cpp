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

vector<int> gph[101010];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        int n; cin >> n;
        int N = (1 << n);
        int M = (1 << (n - 1)) * n;
        for(int i = 0; i < N; ++i) gph[i].clear();
        for(int i = 0; i < M; ++i)
        {
            int x, y; cin >> x >> y;
            gph[x].push_back(y);
            gph[y].push_back(x);
        }

        vector<int> Q;
        Q.push_back(0);
        int ans[N], rev[N];
        bool chc[N]{};
        for(int i = 0; i < N; ++i) ans[i] = -1;
        ans[0] = 0;
        chc[0] = true;

        for(int i = 0; i < N; ++i)
        {
            vector<int> P;
            int cnt = 0;
            for(auto x : Q)
            {
                for(auto y : gph[x])
                {
                    if(ans[y] == -1)
                    {
                        ans[y] = ans[x], P.push_back(y);
                        if(!i) ans[y] = (1 << cnt);
                    }
                    else if(!chc[y]) ans[y] |= ans[x];
                    ++cnt;
                }
            }
            for(auto x : P) chc[x] = true;
            Q = P;
        }

        for(int i = 0; i < N; ++i) rev[ans[i]] = i;

        for(auto x : rev) cout << x << ' '; cout << '\n';

        if(n != 1 && n != 2 && n != 4 && n != 8 && n != 16) cout << "-1\n";
        else
        {
            int A[N];
            int k;
            if(n == 1) k = 0;
            if(n == 2) k = 1;
            if(n == 4) k = 2;
            if(n == 8) k = 3;
            if(n == 16) k = 4;

            for(int i = 0; i < N; ++i)
            {
                int r = 0;
                for(int j = 0; j < n; ++j) if(i >> j & 1)
                {
                    for(int t = 0; t < k; ++t) if(j >> t & 1)
                    {
                        r ^= (1 << t);
                    }
                }
                A[i] = r;
            }
            int B[N];
            for(int i = 0; i < N; ++i) B[rev[i]] = A[i];
            for(int i = 0; i < N; ++i) cout << B[i] << ' ';
            cout << '\n';
        }
    }
}