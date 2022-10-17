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

int par[404];
int fnd(int x) { return x == par[x] ? x : par[x] = fnd(par[x]); }
void uni(int x, int y) { par[fnd(x)] = fnd(y); }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        int n; cin >> n;
        int A[n]; for(auto &i : A) cin >> i, --i;
        for(int i = 0; i < n; ++i) par[i] = i;
        int B[n]; for(int i = 0; i < n; ++i) B[A[i]] = i;
        for(int i = 0; i < n; ++i) uni(i, B[i]);
        for(int i = 0; i < n - 1; ++i)
        {
            if(fnd(i) != fnd(i + 1))
            {
                swap(B[i], B[i + 1]);
                uni(i, i + 1);
            }
        }
        int x = 0;
        for(int i = 0; i < n; ++i) cout << x + 1 << ' ', x = B[x];
        cout << '\n';
    }
}