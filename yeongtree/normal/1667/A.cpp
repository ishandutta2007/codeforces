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

    int n; cin >> n;
    int A[n]; for(auto &i : A) cin >> i;

    long long ans = INF;
    for(int i = 0; i < n; ++i)
    {
        long long t = 0;
        long long pr = 0;
        for(int j = i - 1; j >= 0; --j)
        {
            t += pr / A[j] + 1;
            pr = pr / A[j] * A[j] + A[j];
        }
        pr = 0;
        for(int j = i + 1; j < n; ++j)
        {
            t += pr / A[j] + 1;
            pr = pr / A[j] * A[j] + A[j];
        }
        ans = min(ans, t);
    }

    cout << ans;
}