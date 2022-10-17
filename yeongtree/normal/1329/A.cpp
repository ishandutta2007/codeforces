#include <iostream>
#include <algorithm>
#include <utility>
#define pii pair<int, int>
#define piii pair<int, pii>
#define pll pair<long long, long long>
#define plll pair<long long, pll>
#define ff first
#define ss second
#define ee ss.ff
#define rr ss.ss

using namespace std;

int main()
{
    int n, m; cin >> n >> m;
    int arr[m]; for(auto &i : arr) cin >> i;
    pii A[m]; for(int i = 0; i < m; ++i) A[i] = {arr[i], i};
    long long sum = 0; for(auto i : arr) sum += i;
    if(n - A[m - 1].ff + 1 < m || sum < n) {cout << -1; return 0;}
    int ans[m]{};
    int pr = -1;
    for(int i = 0; i < m; ++i)
    {
        auto x = A[i];
        ans[x.ss] = max(pr + 1ll, n - sum);
        sum -= x.ff;
        pr = ans[x.ss];
        if(pr + x.ff > n) {cout << -1; return 0;}
    }
    {
        for(auto i : ans) cout << i + 1 << ' ';
    }
}