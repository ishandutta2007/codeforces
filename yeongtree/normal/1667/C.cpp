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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    int t = (n + 1) / 3;
    pii A[n - t];
    for(int i = 0; i < n - t; ++i) A[i] = {i + 1, i + 1};
    for(int i = 0; i < t - 1; ++i) A[i * 2].ff += t - i - 1;
    for(int i = 0; i < t - 1; ++i) A[i * 2 + 1].ff -= i + 1;
    cout << n - t << '\n';
    for(int i = 0; i < n - t; ++i) cout << A[i].ff << ' ' << A[i].ss << '\n';
}