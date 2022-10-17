#include <iostream>
#include <utility>
#define pii pair<int, int>
#define piii pair<pii, int>
#define pll pair<long long, long long>
#define ff first
#define ss second

using namespace std;

const int Q = 998244353;

pii egcd(pii x)
{
    if(x.ss == 0) return {1, 0};
    int t = x.ff / x.ss;
    pii ret = egcd({x.ss, x.ff - t * x.ss});
    return {ret.ss, ret.ff - t * ret.ss};
}

int inv(int x)
{
    pii ret = egcd({Q, x});
    return ret.ss < 0 ? ret.ss + Q : ret.ss;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    int inv100 = inv(100);
    int arr[n]; for(auto &i : arr) cin >> i, i = (long long)i * inv100 % Q;

    int A = 1;
    for(auto i : arr) A = (long long)A * i % Q;
    A = inv(A);

    arr[n - 1] = 0;
    int S = 0;
    for(int i = 0; i < n; ++i)
    {
        S = (S + ((long long)A * (Q - arr[i] + 1) % Q * (i + 1) % Q)) % Q;
        A = (long long)A * arr[i] % Q;
    }

    cout << S;
    return 0;
}