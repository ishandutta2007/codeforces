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
const int M = 500000;

ll c2(ll x) {
    return x*(x-1) / 2;
}

int main() {
    int n, Q;
    cin >> n >> Q;
    vi a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vvi d(M + 1);
    vi erat(M + 1);
    for (int i = 0; i < erat.size(); ++i) erat[i] = i;
    for (int i = 2; i*i < erat.size(); ++i) if (erat[i] == i) {
        for (int j = i * i; j < erat.size(); j += i) erat[j] = i;
    }
    vi mu(M + 1, 1);
    for (int i = 2; i < erat.size(); ++i) {
        int p = erat[i];
        int i1 = i / p;
        if (i1 % p == 0) mu[i] = 0;
        else mu[i] = -mu[i1];
    }
    for (int i = 1; i <= M; ++i) for (int j = i; j <= M; j += i) d[j].push_back(i);
    ll res = 0;
    vi cnt(M + 1);
    vi on(n);
    for (int q = 0; q < Q; ++q) {
        int x;
        cin >> x;
        --x;
        //cerr << a[x] << endl;
        for (int i = 0; i < d[a[x]].size(); ++i) {
            int t = d[a[x]][i];
            if (mu[t] == 0) continue;
            res -= mu[t]*c2(cnt[t]);
            if (on[x]) {
                --cnt[t];
            } else {
                ++cnt[t];
            }
            res += mu[t]*c2(cnt[t]);
            //cerr << t << ' ' << cnt[t] << endl;
        }
        on[x] ^= 1;
        cout << res << endl;
    }
    return 0;
}