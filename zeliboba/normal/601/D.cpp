#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <complex>
#include <map>
#include <queue>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
const int mod = 999998981;
const ll P1 = 239;
const ll P2 = 131;

ll mpow(ll x, ll n) {
    ll res = 1;
    while (n) {
        if (n & 1) res = res * x % mod;
        x = x * x % mod;
        n /= 2;
    }
    return res;
}

char s[300100];
vvi gr;
int a1[300100];
int a2[300100];
int b1[300100];
int b2[300100];
int c[300100];
set<pii> h[300100];
int ma = 0, cnt = 0;

void dfs(int v, int p) {
    h[v].insert(pii(s[v], s[v]));
    a1[v] = a2[v] = 1;
    b1[v] = b2[v] = 0;
    for (int i = 0; i < gr[v].size(); ++i) {
        int nv = gr[v][i];
        if (nv == p) continue;
        dfs(nv, v);
        a1[nv] = a1[nv] * P1 % mod;
        a2[nv] = a2[nv] * P2 % mod;
        b1[nv] = (b1[nv] * P1 + s[v]) % mod;
        b2[nv] = (b2[nv] * P2 + s[v]) % mod;
        if (h[nv].size() > h[v].size()) {
            h[v].swap(h[nv]);
            swap(a1[v], a1[nv]);
            swap(b1[v], b1[nv]);
            swap(a2[v], a2[nv]);
            swap(b2[v], b2[nv]);
        }
        ll inv1 = mpow(a1[v], mod - 2);
        ll inv2 = mpow(a2[v], mod - 2);
        ll m1 = a1[nv] * inv1 % mod;
        ll m2 = a2[nv] * inv2 % mod;
        ll add1 = (b1[nv] - b1[v] + mod) * inv1 % mod;
        ll add2 = (b2[nv] - b2[v] + mod) * inv2 % mod;
        for (auto x : h[nv]) {
            int x1 = (m1 * x.first + add1) % mod; // av*(m*x + add) = anv*x + bnv -bv
            int x2 = (m2 * x.second + add2) % mod;
            h[v].insert(pii(x1, x2));
        }
    }
//    cerr << v << ' ' << h[v].size() << endl;
    int cur = c[v] + h[v].size();
    if (cur == ma) ++cnt;
    else if (cur > ma) {
        ma = cur;
        cnt = 1;
    }
}

int main() {
    int n;
    scanf("%d", &n);
   /* pw[0] = pwi[0] = 1;
    //ll P1 = mpow(P, mod - 2);
    ll P1 = mpow(P, (1LL << 63) - 1);
    for (int i = 1; i <= n + 1; ++i) pw[i] = pw[i-1] * P;// % mod;
    for (int i = 1; i <= n + 1; ++i) pwi[i] = pwi[i-1] * P1;// % mod;*/
    for (int i = 0; i < n; ++i) scanf("%d", &c[i]);
    scanf("%s", s);
    gr.resize(n);
    for (int i = 0; i < n-1; ++i) {
        int u,v;
        scanf("%d%d", &u, &v);
        --u; --v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    dfs(0, -1);
    printf("%d\n%d\n", ma, cnt);
    return 0;
}