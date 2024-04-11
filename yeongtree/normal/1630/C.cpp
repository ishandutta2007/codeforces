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
    int A[n]; for(auto &i : A) cin >> i, --i;

    int X[n], Y[n];
    for(int i = 0; i < n; ++i) X[i] = Y[i] = -1;
    for(int i = 0; i < n; ++i) Y[A[i]] = i;
    for(int i = n - 1; i >= 0; --i) X[A[i]] = i;

    vector<pii> W;
    for(int i = 0; i < n; ++i) if(X[i] < Y[i]) W.push_back({X[i], Y[i]});
    sort(W.begin(), W.end(), [](pii x, pii y){return pii{x.ff, -x.ss} < pii{y.ff, -y.ss};});

    vector<pii> V;
    for(auto i : W) if(V.empty() || V.back().ss < i.ss) V.push_back(i);
    V.push_back({n, n});

    int ed = -1, ked = -1, ans = 1;
    for(int i = 0; i < (int)V.size() - 1; ++i)
    {
        if(ed < V[i].ff)
        {
            ans += ed;
            ans -= V[i].ff + 1;
            ed = ked = V[i].ss;
        }
        else
        {
            if(ked < V[i + 1].ff)
            {
                --ans;
                ked = V[i].ss;
            }
            ed = V[i].ss;
        }
    }

    cout << ans + ed;
}