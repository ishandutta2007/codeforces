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
        int n; cin >> n;
        int A[2 * n][2 * n];
        for(auto &i : A) for(auto &j : i) cin >> j;
        long long ans = 0;
        for(int i = n; i < 2 * n; ++i) for(int j = n; j < 2 * n; ++j) ans += A[i][j];
        ans += min({ A[0][n], A[0][2 * n - 1], A[n - 1][n], A[n - 1][2 * n - 1], A[n][0], A[n][n - 1], A[2 * n - 1][0], A[2 * n - 1][n - 1] });
        cout << ans << '\n';
    }
}