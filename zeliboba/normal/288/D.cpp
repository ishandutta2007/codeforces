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
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;

vvi gr;
ll res = 0;
vl was,cnt,cnt2;
    int n;

ll c2(ll x) {
    return x*(x-1)/2;
}

void dfs(int v, int pr) {
    if (was[v])
        return;
    was[v] = 1;
    cnt[v] = 1;
    ll sum = c2(n-1);
    for (int i = 0; i < gr[v].size(); ++i) if (gr[v][i] != pr) {
        dfs(gr[v][i], v);
        cnt[v] += cnt[gr[v][i]];
        cnt2[v] += cnt2[gr[v][i]];
        res += cnt2[gr[v][i]] * (n-1-cnt[gr[v][i]]);
    }
    sum -= cnt2[v] + c2(n-cnt[v]);
    ll res2 = 0;
    for (int i = 0; i < gr[v].size(); ++i) if (gr[v][i] != pr) {
        res2 += cnt2[gr[v][i]] * (cnt2[v]-cnt2[gr[v][i]]);
        ll cur = cnt[gr[v][i]] * (n-cnt[gr[v][i]]-1);
        res += cnt2[gr[v][i]] * (sum - cur);
    }
    assert(res2 % 2 == 0);
    res += res2/2;
    //res += (cnt[v]-1) * c2(n-cnt[v]) + (n-cnt[v])*cnt2[v];
    cnt2[v] = c2(cnt[v]);
}

int main() {
    cin >> n;
    gr.resize(n);
    was.assign(n, 0);
    cnt.assign(n, 0);
    cnt2.assign(n, 0);
    for (int i = 0; i < n-1; ++i) {
        int a,b;
        scanf("%d%d",&a,&b);
        --a;--b;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    dfs(0, -1);
    cout << 2*res << endl;
    return 0;
}