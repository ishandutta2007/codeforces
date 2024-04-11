#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <utility>
#include <tuple>
#include <set>
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

int seg[2020202];
void init(int ind, int s, int e)
{
    seg[ind] = INF;
    if(s + 1 == e) return;
    int mid = s + e >> 1;
    init(ind << 1, s, mid);
    init(ind << 1 | 1, mid, e);
}
void upd(int ind, int s, int e, int pos, int x)
{
    if(s + 1 == e)
    {
        seg[ind] = min(seg[ind], x);
        return;
    }

    int mid = s + e >> 1;
    if(pos < mid) upd(ind << 1, s, mid, pos, x);
    else upd(ind << 1 | 1, mid, e, pos, x);
    seg[ind] = min(seg[ind << 1], seg[ind << 1 | 1]);
}
int qry(int ind, int s, int e, int l, int r)
{
    if(l <= s && e <= r) return seg[ind];
    if(e <= l || r <= s) return INF;

    int mid = s + e >> 1;
    return min(qry(ind << 1, s, mid, l, r), qry(ind << 1 | 1, mid, e, l, r));
}

int f(int x)
{
    if(x < 0) return 2;
    if(x == 0) return 1;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        int n; cin >> n;
        int A[n]; for(auto &i : A) cin >> i;
        long long ps[n + 1]; ps[0] = 0;
        for(int i = 0; i < n; ++i) ps[i + 1] = ps[i] + A[i];
        vector<long long> pr(ps, ps + n + 1);
        sort(pr.begin(), pr.end());
        pr.resize(unique(pr.begin(), pr.end()) - pr.begin());
        for(auto &i : ps) i = lower_bound(pr.begin(), pr.end(), i) - pr.begin();
        int N = pr.size();

        init(1, 0, N);
        upd(1, 0, N, ps[0], 0);
        int dp[n + 1]; dp[0] = 0;
        for(int i = 1; i <= n; ++i)
        {
            dp[i] = min(qry(1, 0, N, 0, ps[i]), dp[i - 1] + f(A[i - 1]));
            upd(1, 0, N, ps[i], dp[i]);
        }

        cout << n - dp[n] << '\n';
    }
}