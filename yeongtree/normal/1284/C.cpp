#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; long long Q; cin >> n >> Q;
    long long fact[n + 1];
    fact[0] = 1;
    for(int i = 1; i <= n; ++i)
        fact[i] = fact[i - 1] * i % Q;
    long long ans = 0;
    for(int i = 1; i <= n; ++i)
        ans = (ans + fact[i] * fact[n - i + 1] % Q * (n - i + 1) % Q) % Q;
    cout << ans;
    return 0;
}