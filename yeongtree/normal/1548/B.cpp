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
        long long A[n]; for(auto &i : A) cin >> i;
        long long B[n - 1]; for(int i = 0; i < n; ++i) B[i] = A[i + 1] - A[i];
        for(auto &i : B)
        {
            if(i < 0) i = -i;
        }

        long long S[n - 1][20];
        for(int i = 0; i < n - 1; ++i) S[i][0] = B[i];
        for(int j = 1; j < 20; ++j)
        {
            for(int i = 0; i < n - 1; ++i)
            {
                if(i + (1 << (j - 1)) >= n - 1) S[i][j] = S[i][j - 1];
                else S[i][j] = __gcd(S[i][j - 1], S[i + (1 << (j - 1))][j - 1]);
            }
        }

        int ans = 0;
        for(int i = 0; i < n - 1; ++i) if(B[i] != 1)
        {
            int x = i + 1;
            long long t = B[i];
            for(int j = 19; j >= 0; --j) if(x + (1 << j) <= n - 1)
            {
                long long s = __gcd(t, S[x][j]);
                if(s != 1) x += (1 << j), t = s;
            }
            ans = max(ans, x - i);
        }

        cout << ans + 1 << '\n';
    }
}