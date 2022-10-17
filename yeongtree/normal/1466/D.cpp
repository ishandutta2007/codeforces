#include <iostream>
#include <vector>
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
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        int n; cin >> n;
        long long ans = 0;
        int A[n];
        for(auto &i : A) cin >> i, ans += i;
        int cnt[n]{};
        for(int i = 1; i < n; ++i)
        {
            int x, y; cin >> x >> y; --x; --y;
            ++cnt[x]; ++cnt[y];
        }
        vector<int> V;
        for(int i = 0; i < n; ++i) for(int j = 1; j < cnt[i]; ++j) V.push_back(A[i]);
        sort(V.begin(), V.end(), greater<int>());
        cout << ans << ' ';
        for(int i = 0; i < n - 2; ++i) ans += V[i], cout << ans << ' ';
        cout << '\n';
    }
}