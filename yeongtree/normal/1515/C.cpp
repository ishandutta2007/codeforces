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

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        int n, m, x; cin >> n >> m >> x;
        pii A[n]; for(int i = 0; i < n; ++i) cin >> A[i].ff, A[i].ss = i;
        sort(A, A + n);
        int ans[n];
        for(int i = 0; i < n; ++i) ans[A[i].ss] = i % m + 1;
        cout << "YES\n";
        for(auto i : ans) cout << i << ' ';
        cout << '\n';
    }
}