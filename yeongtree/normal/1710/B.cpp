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

    int T; cin >> T;
    while(T--)
    {
        int n, m; cin >> n >> m;
        pll A[n];
        vector<pll> V;
        for(auto &i : A)
        {
            cin >> i.ff >> i.ss;
            i.ff += INF;
            V.push_back({i.ff - i.ss, 1});
            V.push_back({i.ff, -1});
            V.push_back({i.ff, -1});
            V.push_back({i.ff + i.ss, 1});
        }
        sort(V.begin(), V.end());
        vector<pll> W;
        long long pr = 0, val = 0, des = 0;
        for(auto i : V)
        {
            val += (i.ff - pr) * des;
            des += i.ss;
            pr = i.ff;
            if(val > m) W.push_back({pr, val - m});
        }

        int N = (int)W.size();
//        for(auto i : W) cout << i.ff - INF << ' ' << i.ss << endl;
        long long L[N + 1], R[N + 1];
        L[0] = -10ll * INF;
        for(int i = 0; i < N; ++i) L[i + 1] = max(L[i], W[i].ss - W[i].ff);
        R[N] = -10ll * INF;
        for(int i = N - 1; i >= 0; --i) R[i] = max(R[i + 1], W[i].ss + W[i].ff);

        for(int i = 0; i < n; ++i)
        {
            int k = lower_bound(W.begin(), W.end(), pll{A[i].ff, 0}) - W.begin();
            if(A[i].ss - A[i].ff >= L[k] && A[i].ss + A[i].ff >= R[k]) cout << 1;
            else cout << 0;
        }
        cout << '\n';
    }
}