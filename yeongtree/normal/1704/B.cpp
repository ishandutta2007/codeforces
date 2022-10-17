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
        int n, x; cin >> n >> x;
        int A[n]; for(auto &i : A) cin >> i;
        int l = A[0] - x, r = A[0] + x;
        int ans = 0;
        for(int i = 1; i < n; ++i)
        {
            l = max(l, A[i] - x);
            r = min(r, A[i] + x);
            if(l > r) { ++ans, l = A[i] - x, r = A[i] + x; }
        }
        cout << ans << '\n';
    }
}