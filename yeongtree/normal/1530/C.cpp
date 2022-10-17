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
        int A[n], B[n];
        for(auto &i : A) cin >> i;
        for(auto &i : B) cin >> i;

        sort(A, A + n, greater<int>());
        sort(B, B + n, greater<int>());

        int C[n + 1]{}, D[n + 1]{};
        for(int i = 1; i <= n; ++i) C[i] = A[i - 1] + C[i - 1];
        for(int i = 1; i <= n; ++i) D[i] = B[i - 1] + D[i - 1];

        int s = -1, e = n * 3 + 100;
        while(s + 1 < e)
        {
            int mid = s + e >> 1;
            int k = mid + n;
            k = k - k / 4;
            int t = max(0, k - mid);
            if(100 * (k - t) + C[t] >= D[min(n, k)]) e = mid;
            else s = mid;
        }

        cout << e << '\n';
    }
}