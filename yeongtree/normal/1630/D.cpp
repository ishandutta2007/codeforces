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
const long long INF = (long long)1e18 + 7;

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        int n, k; cin >> n >> k;
        int A[n]; for(auto &i : A) cin >> i;
        int x; cin >> x;
        for(int i = 1; i < k; ++i)
        {
            int y; cin >> y;
            x = __gcd(x, y);
        }

        vector<int> V[x];
        int cnt[x]{};
        long long sum = 0;
        for(int i = 0; i < n; ++i)
        {
            if(A[i] >= 0) V[i % x].push_back(A[i]), sum += A[i];
            else ++cnt[i % x], V[i % x].push_back(-A[i]), sum -= A[i];
        }

        for(int i = 0; i < x; ++i) sort(V[i].begin(), V[i].end());

        long long ans1 = sum, ans2 = sum;

        for(int i = 0; i < x; ++i)
        {
            if(cnt[i] & 1) ans1 -= V[i][0] * 2;
            else ans2 -= V[i][0] * 2;
        }

        cout << max(ans1, ans2) << '\n';
    }
}