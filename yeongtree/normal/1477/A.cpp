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
        int n; long long k; cin >> n >> k;
        long long A[n]; for(int i = 0; i < n; ++i) cin >> A[i];
        long long g = A[1] - A[0];
        for(int i = 2; i < n; ++i) g = __gcd(A[i] - A[0], g);

        bool flag = false;
        for(int i = 0; i < n; ++i)
        {
            if((k - A[i]) % g == 0) flag = true;
        }

        cout << (flag ? "YES" : "NO") << '\n';
    }
}