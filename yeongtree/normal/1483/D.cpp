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

using namespace std;

const long long INF = (long long)1e18 + 100;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    long long C[n][n];
    for(auto &i : C) for(auto &j : i) j = INF;
    int m; cin >> m;
    for(int i = 0; i < m; ++i)
    {
        int x, y, d; cin >> x >> y >> d; --x; --y;
        C[x][y] = C[y][x] = d;
    }

    long long D[n][n];
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            D[i][j] = C[i][j];
    for(int i = 0; i < n; ++i) D[i][i] = 0;
    for(int j = 0; j < n; ++j)
        for(int i = 0; i < n; ++i)
            for(int k = 0; k < n; ++k)
                if(D[i][j] + D[j][k] < D[i][k])
                    D[i][k] = D[i][j] + D[j][k];

    long long E[n][n]{};
    int q; cin >> q;
    for(int i = 0; i < q; ++i)
    {
        int x, y, d; cin >> x >> y >> d; --x; --y;
        E[x][y] = E[y][x] = d;
    }

    long long F[n][n]{};
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            for(int k = 0; k < n; ++k)
                F[i][j] = max(F[i][j], E[j][k] - D[i][k]);

    int ans = 0;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
    {
        bool flag = false;
        for(int k = 0; k < n; ++k)
            if(F[i][k] >= C[i][j] + D[j][k]) flag = true;
        if(flag) ++ans;
    }

    cout << ans / 2;
}