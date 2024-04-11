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
        int A[n]; for(auto &i : A) cin >> i, --i;
        int C[n]{};
        for(int i = 0; i < n; ++i) ++C[A[i]];

        int x = 0, l = 0, r = 0;
        pii ans = {0, n};
        for(; l < n; ++l)
        {
            while(r < n && x < n - x + k) x += C[r++];
            if(x >= n - x + k && ans.ss - ans.ff > r - l) ans = {l, r};
            x -= C[l];
        }

        cout << ans.ff + 1 << ' ' << ans.ss << '\n';
        int cnt = 1, s = 0, pr = 0;
        for(int i = 0; i < n; ++i)
        {
            if(ans.ff <= A[i] && A[i] < ans.ss) ++s;
            else --s;
            if(s == 1 && cnt < k) cout << pr + 1 << ' ' << i + 1 << '\n', pr = i + 1, ++cnt, s = 0;
        }
        cout << pr + 1 << ' ' << n << '\n';
    }
}