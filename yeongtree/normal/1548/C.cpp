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
const int Q = (int)1e9 + 7;

using namespace std;

int fact[6060606];
int revf[6060606];

int comb(int n, int r) { return 1ll * fact[n] * revf[r] % Q * revf[n - r] % Q; }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    fact[0] = 1; for(int i = 1; i < 6060606; ++i) fact[i] = 1ll * fact[i - 1] * i % Q;
    revf[0] = revf[1] = 1; for(int i = 2; i < 6060606; ++i) revf[i] = Q - 1ll * revf[Q % i] * (Q / i) % Q;
    for(int i = 2; i < 6060606; ++i) revf[i] = 1ll * revf[i] * revf[i - 1] % Q;

    int n; cin >> n;
    int ans[3 * n + 1]{};
    ans[3 * n] = 1;
    ans[3 * n - 1] = 3 * n;
    for(int i = 3 * n - 2; i >= 0; --i)
    {
        int t = comb(3 * n + 3, i + 3);
        ans[i] = (Q + (t - 3ll * ans[i + 1] - 3ll * ans[i + 2]) % Q) % Q;
    }

    int T; cin >> T;
    while(T--)
    {
        int x; cin >> x;
        cout << ans[x] << '\n';
    }
}