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
const int Q = 998'244'353;

using namespace std;

int fact[101010];
int revf[101010];

int comb(int n, int r) { return 1ll * fact[n] * revf[n - r] % Q * revf[r] % Q; }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    fact[0] = 1; for(int i = 1; i < 101010; ++i) fact[i] = 1ll * fact[i - 1] * i % Q;
    revf[0] = revf[1] = 1; for(int i = 2; i < 101010; ++i) revf[i] = Q - 1ll * (Q / i) * (revf[Q % i]) % Q;
    for(int i = 2; i < 101010; ++i) revf[i] = 1ll * revf[i - 1] * revf[i] % Q;

    int T; cin >> T;
    while(T--)
    {
        int n; cin >> n;
        int pr = 0;
        int a = 0, b = 0;
        for(int i = 0; i < n; ++i)
        {
            char c; cin >> c;
            if(c == '0') ++a, pr = 0;
            else if(pr == 1) ++b, pr = 0;
            else pr = 1;
        }
        cout << comb(a + b, a) << '\n';
    }
}