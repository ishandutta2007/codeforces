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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    int X[n], Y[n], C[n];
    for(int i = 0; i < n; ++i) cin >> X[i] >> Y[i] >> C[i];

    int ps[n + 1]{}, D[n];
    for(int i = 0; i < n; ++i)
    {
        int id = lower_bound(X, X + n, Y[i]) - X;
        D[i] = ((Q + ps[i] - ps[id]) % Q + (X[i] - Y[i])) % Q;
        ps[i + 1] = (ps[i] + D[i]) % Q;
    }

    int ans = (X[n - 1] + 1) % Q;
    for(int i = 0; i < n; ++i) if(C[i]) ans = (ans + D[i]) % Q;
    cout << ans;
}