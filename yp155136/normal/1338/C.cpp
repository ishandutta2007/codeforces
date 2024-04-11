#include <bits/stdc++.h>
using namespace std;
// Compile with "(g++) -std=c++11 -Wall -Wextra -Wconversion -Wshadow -Dcychien"
#ifdef cychien
#define debug(...) do {\
	fprintf(stderr, "%s - %d : (%s) = ", __PRETTY_FUNCTION__, __LINE__, #__VA_ARGS__);\
    _DO(__VA_ARGS__);\
}while(0) 
template<typename I> void _DO(I&&x) {cerr << x << '\n';}
template<typename I, typename ...T> void _DO(I&&x,T&&...tail) {cerr << x << ", "; _DO(tail...);}
#define IOS
#else
#define debug(...)
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#endif
#define W(v) for(auto it = (v).begin(); it != (v).end(); it++){\
                 it++;\
                 int flag = (it == (v).end());\
                 it--;\
                 cout << *it << " \n"[flag];\
             }
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FOR1(i, n) for(int i = 1; i <= n; i++)
#define pb push_back
#define mp make_pair
#define rsz resize
#define X first
#define Y second
#define SZ(x) (ll)x.size()
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort(ALL(x))
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
const int NF = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9 + 7;
const ld PI = 3.14159265358979323846264338327950288;
#define int long long
int32_t main() {
    IOS;
    ll magic[4][4] = {{0, 0, 0, 0},
                    {0, 1, 2, 3},
                    {0, 2, 3, 1},
                    {0, 3, 1, 2}};
    int T = 1;
    cin >> T;
    while (T--){
        ll n;
        cin >> n;
        ll ok;
        ll nn = n / 3 + (n % 3 == 0 ? 0 : 1);
        for (ll i = 1; ; i++){
            if (nn <= ((1ll << (2 * i)) - 1) / 3){
                ok = i;
                break;
            }
        }
        ll rest = nn - (((1ll << (2 * (ok - 1))) - 1) / 3 + 1);
        int idx = n % 3 + (n % 3 == 0 ? 3 : 0);
        ll ans = (1LL << ((ok - 1) << 1)) * idx;
        for (ll i = 0; rest; i++){
            ll residue = rest % 4;
            debug(idx, residue);
            ans += magic[idx][residue] * (1LL << (2 * i));
            rest /= 4;
        }
        cout << ans << '\n';
    }
    return 0;
}