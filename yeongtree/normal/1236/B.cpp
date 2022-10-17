#include <iostream>

using namespace std;

const int Q = (int)1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    long long pow = 1;
    long long __pow = 2;
    while(m)
    {
        if(m & 1) pow *= __pow;
        pow %= Q;
        __pow *= __pow;
        __pow %= Q;
        m >>= 1;
    }
    pow -= 1;
    if(pow < 0) pow += Q;

    long long ans = 1;
    long long __ans = pow;
    while(n)
    {
        if(n & 1) ans *= __ans;
        ans %= Q;
        __ans *= __ans;
        __ans %= Q;
        n >>= 1;
    }
    cout << ans;
    return 0;
}