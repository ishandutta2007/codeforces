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

int MAX = 1e5 + 10;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, T; cin >> n >> T;
    int A[n]; for(auto &i : A) cin >> i;
    vector<int> ls[MAX];
    for(int i = 0; i < n; ++i)
    {
        int t = A[i];
        for(int j = 2; j * j <= t; ++j) if(t % j == 0)
        {
            ls[j].push_back(i);
            while(t % j == 0) t /= j;
        }
        if(t > 1) ls[t].push_back(i);
    }

    int nxt[n]; for(auto &i : nxt) i = n;
    for(int i = 0; i < MAX; ++i)
    {
        for(int j = 0; j < (int)ls[i].size() - 1; ++j)
            nxt[ls[i][j]] = min(nxt[ls[i][j]], ls[i][j + 1]);
    }
    for(int i = n - 2; i >= 0; --i) nxt[i] = min(nxt[i + 1], nxt[i]);

    int sp[n + 1][20];
    for(int i = 0; i < n; ++i) sp[i][0] = nxt[i]; sp[n][0] = n;
    for(int j = 1; j < 20; ++j) for(int i = 0; i < n + 1; ++i) sp[i][j] = sp[sp[i][j - 1]][j - 1];

    while(T--)
    {
        int l, r; cin >> l >> r; --l;
        int ans = 1;
        for(int j = 19; j >= 0; --j) if(sp[l][j] < r) ans += (1 << j), l = sp[l][j];
        cout << ans << '\n';
    }
}