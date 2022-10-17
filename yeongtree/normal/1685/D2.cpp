#include <iostream>
#include <vector>
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

int par[404];
int fnd(int x) { return x == par[x] ? x : par[x] = fnd(par[x]); }
void uni(int x, int y) { par[fnd(x)] = fnd(y); }
int C[404];
bool chc[404];
set<int> T;

bool f(int x, int n)
{
    if(chc[x])
    {
        int cnt = 0;
        for(int i = 0; i < n; ++i) if(chc[i]) ++cnt;
        return cnt == n;
    }
    chc[x] = true;

    pii mn = {INF, -1};

    set<int> S; S.insert(fnd(x));
    for(auto it = T.lower_bound(x); it != T.begin() && !S.count(fnd(*--it)); )
    {
        S.insert(fnd(*it));
        mn = min(mn, {C[*it], *it});
    }

    S.clear(); S.insert(fnd(x));
    for(auto it = T.lower_bound(x); ++it != T.end() && !S.count(fnd(*it)); )
    {
        S.insert(fnd(*it));
        mn = min(mn, {C[*it], *it});
    }

    if(mn.ff > C[x]) if(f(C[x], n)) return true;
    if(mn.ff < INF)
    {
        int D[n], P[n]; for(int i = 0; i < n; ++i) D[i] = C[i], P[i] = par[i];
        if(mn.ss < x) for(auto it = T.lower_bound(mn.ss); *it != x; ++it) swap(C[*it], C[*next(it)]), uni(*it, *next(it));
        else for(auto it = T.lower_bound(mn.ss); *it != x; --it) swap(C[*it], C[*prev(it)]), uni(*it, *prev(it));
        T.erase(x);
        if(f(C[x], n)) return true;
        T.insert(x);
        for(int i = 0; i < n; ++i) C[i] = D[i], par[i] = P[i];
    }

    chc[x] = false;
    return false;
}

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
        ::T.clear();
        for(int i = 0; i < n; ++i) C[i] = B[i], chc[i] = false, ::T.insert(i);
        f(0, n);
        int x = 0;
        for(int i = 0; i < n; ++i) cout << x + 1 << ' ', x = C[x];
        cout << '\n';
    }
}