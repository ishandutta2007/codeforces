#include <iostream>
#include <vector>
#include <utility>
#define pii pair<int, int>
#define piii pair<pii, int>
#define pll pair<long long, long long>
#define ff first
#define ss second

using namespace std;

long long G, B;
vector<pii> gph[202020];
int sz[202020];
int n;

int getsz(int x)
{
    sz[x] = 1;
    for(auto &y : gph[x]) if(sz[y.ff] == 0) sz[x] += getsz(y.ff);
    return sz[x];
}

int getcen(int x, int par)
{
    for(auto &y : gph[x])
    {
        if(y.ff == par) continue;
        if(sz[y.ff] > n / 2) return getcen(y.ff, x);
    }
    return x;
}

int sol(int x, int par)
{
    long long pow = 0;
    int ssz = 1;
    for(auto &y : gph[x])
    {
        if(y.ff == par) pow = y.ss;
        else ssz += sol(y.ff, x);
    }
    G += (ssz & 1) * pow;
    B += ssz * pow;
    return ssz;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        cin >> n; n <<= 1;

        for(int i = 1; i < n; ++i)
        {
            int s, e, x; cin >> s >> e >> x; --s; --e;
            gph[s].push_back({e, x});
            gph[e].push_back({s, x});
        }

        getsz(0);
        int cen = getcen(0, -1);
        sol(cen, -1);
        cout << G << ' ' << B << '\n';

        G = B = 0;
        for(int i = 0; i < n; ++i) vector<pii>().swap(gph[i]);
        for(int i = 0; i < n; ++i) sz[i] = 0;
    }
}