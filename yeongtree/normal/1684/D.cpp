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
        long long sum = 0;
        int A[n]; for(auto &i : A) cin >> i, sum += i;
        for(int i = 0; i < n; ++i) A[i] -= n - i - 1;
        sort(A, A + n, greater<int>());
        long long B[n + 1]{};
        for(int i = 1; i <= n; ++i) B[i] = B[i - 1] + A[i - 1];
        long long ans = 0;
        for(int i = 0; i <= k; ++i) ans = max(ans, B[i] + 1ll * i * (i - 1) / 2);
        cout << sum - ans << '\n';
    }
}