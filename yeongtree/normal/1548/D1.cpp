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

int myabs(int x) { return (x < 0 ? -x : x); }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    pii A[n];
    for(auto &i : A) cin >> i.ff >> i.ss;

    bool gph[n][n]; for(auto &i : gph) for(auto &j : i) j = false;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < i; ++j)
        {
            gph[i][j] = (__gcd(myabs(A[i].ff - A[j].ff), myabs(A[i].ss - A[j].ss)) % 4 == 0);
            gph[j][i] = gph[i][j];
        }
    }

    int C[n]{};
    for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) if(gph[i][j]) ++C[i];

    long long ans1 = 0, ans2 = 0;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < i; ++j) if(gph[i][j])
        {
            int t = (C[i] + C[j] - 2) / 2;
            ans1 += t;
            ans2 += n - t - 2;
        }
    }

    cout << ans1 / 3 + ans2;
}