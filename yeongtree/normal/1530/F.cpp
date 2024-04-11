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
const int Q = 31'607;

using namespace std;

int R[101010];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    R[0] = R[1] = 1; for(int i = 2; i < Q; ++i) R[i] = Q - (Q / i) * (R[Q % i]) % Q;

    int n; cin >> n;
    int A[n][n];
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            int x; cin >> x;
            x = x * R[10000] % Q;
            A[i][j] = x;
        }
    }

    int ans = 1;
    int B[n];
    for(int i = 0; i < n; ++i)
    {
        int tmp = 1;
        for(int j = 0; j < n; ++j)
        {
            tmp = tmp * A[i][j] % Q;
        }
        B[i] = tmp;
        tmp = (Q + 1 - tmp) % Q;
        ans = ans * tmp % Q;
    }
    ans = (Q + 1 - ans) % Q;
    int C = 1;

    for(int i = 0; i < (1 << n); ++i)
    {
        int tmp = C;
        if(i)
        {
            for(int j = 0; j < n; ++j)
                tmp = tmp * (Q + 1 - B[j]) % Q;
            if(__builtin_parity(i)) ans = (ans + tmp) % Q;
            else ans = (Q + ans - tmp) % Q;
        }

        tmp = C;
        for(int j = 0; j < n; ++j)
        {
            if(i >> j & 1) tmp = tmp * (Q + 1 - B[j]) % Q;
            else tmp = tmp * A[j][j] % Q, tmp = tmp * (Q + 1 - B[j] * R[A[j][j]] % Q) % Q;
        }
        if(!__builtin_parity(i)) ans = (ans + tmp) % Q;
        else ans = (Q + ans - tmp) % Q;

        tmp = C;
        for(int j = 0; j < n; ++j)
        {
            if(i >> (n - j - 1) & 1) tmp = tmp * (Q + 1 - B[j]) % Q;
            else tmp = tmp * A[j][n - j - 1] % Q, tmp = tmp * (Q + 1 - B[j] * R[A[j][n - j - 1]] % Q) % Q;
        }
        if(!__builtin_parity(i)) ans = (ans + tmp) % Q;
        else ans = (Q + ans - tmp) % Q;

        tmp = C;
        for(int j = 0; j < n; ++j)
        {
            bool f1 = !(i >> j & 1);
            bool f2 = !(i >> (n - j - 1) & 1);
            if(j * 2 + 1 == n) f2 = false;

            if(!f1 && !f2) tmp = tmp * (Q + 1 - B[j]) % Q;
            else if(f1 && !f2) tmp = tmp * A[j][j] % Q, tmp = tmp * (Q + 1 - B[j] * R[A[j][j]] % Q) % Q;
            else if(!f1 && f2) tmp = tmp * A[j][n - j - 1] % Q, tmp = tmp * (Q + 1 - B[j] * R[A[j][n - j - 1]] % Q) % Q;
            else tmp = tmp * A[j][j] % Q * A[j][n - j - 1] % Q,
                tmp = tmp * (Q + 1 - B[j] * R[A[j][j]] % Q * R[A[j][n - j - 1]] % Q) % Q;
        }
        if(__builtin_parity(i)) ans = (ans + tmp) % Q;
        else ans = (Q + ans - tmp) % Q;

        if(i < (1 << n) - 1)
        {
            int k = 0;
            while(i >> k & 1)
            {
                for(int j = 0; j < n; ++j)
                    B[j] = B[j] * A[j][k] % Q, C = C * R[A[j][k]] % Q;
                ++k;
            }
            for(int j = 0; j < n; ++j)
                B[j] = B[j] * R[A[j][k]] % Q, C = C * A[j][k] % Q;
        }
    }

    cout << ans << '\n';
//    cout << ans * 16 % Q;
}