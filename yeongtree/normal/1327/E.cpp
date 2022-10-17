#include <iostream>

using namespace std;

const int Q = 998244353;
int mpow(int a, int x)
{
    int ret = 1;
    while(x)
    {
        if(x & 1) ret = 1ll * ret * a % Q;
        a = 1ll * a * a % Q;
        x >>= 1;
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    for(int i = 1; i < n; ++i)
    {
        int ans = 0;
        ans += 1ll * 18 * mpow(10, n - i - 1) % Q;
        if(n - i - 2 >= 0) ans += 1ll * 81 * (n - i - 1) * mpow(10, n - i - 2) % Q;
        ans = 1ll * ans * 10 % Q;
        cout << ans << ' ';
    }
    cout << 10;
}