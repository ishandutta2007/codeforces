#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define pii pair<int, int>
#define piii pair<int, pii>
#define pll pair<long long, long long>
#define plll pair<long long, pll>
#define ff first
#define ss second
#define ee ss.ff
#define rr ss.ss

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        int n, m; cin >> n >> m;
        int A[n], B[m];
        for(auto &i : A) cin >> i, --i;
        for(auto &i : B) cin >> i;
        sort(A, A + n);
        long long D[m + 1]{}, E[n + 1]{};
        for(int i = 1; i <= m; ++i) D[i] = D[i - 1] + B[i - 1];
        for(int i = 1; i <= n; ++i) E[i] = E[i - 1] + B[A[i - 1]];
        long long ans = 8e18;
        int mn = m;
        for(int i = n; i >= 0; --i)
        {
            if(i < n) mn = min(mn, A[i] + n - i);
            if(n - i <= mn) ans = min(ans, D[n - i] + E[i]);
        }
        cout << ans << '\n';
    }
}